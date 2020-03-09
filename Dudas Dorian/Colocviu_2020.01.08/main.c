#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME_LENGTH 30
#define MAX_QUEST_TITLE_LENGTH 50
#define REQUIREMENT 100

typedef struct
{
    char* name;
    char Class;
    int power;
} heroes;

typedef struct
{
    char* title;
    char* reqClass;
    int reqPow;
    int exp;
} quests;

void initializeHeroes(heroes *hero)
{
    hero->name=(char*)malloc(sizeof(char)*MAX_NAME_LENGTH);
}

void initializeQuests(quests *quest)
{
    quest->title=(char*)malloc(sizeof(char)*MAX_QUEST_TITLE_LENGTH);
    quest->reqClass=(char*)malloc(sizeof(char)*10);
}

void attributeHeroDetails(heroes *hero, FILE *f, int numberOfHeroes)
{
    char *p;
    char* strbuf=(char*)malloc(sizeof(char)*100);
    for(int i=0; i<numberOfHeroes; i++)
    {
        fgets(strbuf,100,f);
        p=strtok(strbuf,",");
        strcpy(hero[i].name,p);
        p=strtok(NULL,",\n");
        hero[i].Class=p[0];
        p=strtok(NULL,",\n");
        hero[i].power=0;
        for(int j=0; j<strlen(p); j++)
        {
            hero[i].power=hero[i].power*10+(p[j]-'0');
        }
    }
}

void attributeQuestDetails(quests *quest, FILE *f, int numberOfQuests)
{
    char *p;
    char* strbuf=(char*)malloc(sizeof(char)*100);
    for(int i=0; i<numberOfQuests; i++)
    {
        fgets(strbuf,100,f);
        p=strtok(strbuf,",");
        strcpy(quest[i].title,p);
        p=strtok(NULL,",\n");
        strcpy(quest[i].reqClass,p);
        p=strtok(NULL,",\n");
        quest[i].reqPow=0;
        for(int j=0; j<strlen(p); j++)
        {
            quest[i].reqPow=quest[i].reqPow*10+(p[j]-'0');
        }
        p=strtok(NULL,",\n");
        quest[i].exp=0;
        for(int j=0; j<strlen(p); j++)
        {
            quest[i].exp=quest[i].exp*10+(p[j]-'0');
        }
    }
}

void sortHeroesByPower(heroes* hero, int n)
{
    bool ok=true;
    while(ok)
    {
        ok=false;
        for(int i=0; i<n; i++)
        {
            if(hero[i].power>hero[i+1].power)
            {
                int aux=hero[i].power;
                hero[i].power=hero[i+1].power;
                hero[i+1].power=aux;
                ok=true;
            }
        }
    }
}

void countClasses(char* s, int letter[])
{
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]=='D')
        {
            letter[0]++;
        }

        if(s[i]=='H')
        {
            letter[1]++;
        }
        if(s[i]=='T')
        {
            letter[2]++;
        }
    }
}


void printVictory(FILE *o, char* group, char* questTitle, int enemyPow, int heroPow, int exp)
{
    fprintf(o, "\n%s went on to complete \"%s\" - SUCCESS (%d vs %d) and gained %d xp\n", group, questTitle, enemyPow, heroPow, exp);
}


void printFailture(FILE *o, char* title, char missingClass)
{
    fprintf(o, "\n\nCannot execute mission \"%s\" not enough heroes of type %c\n", title, missingClass);
}

void checkAvailabilityAndPower(FILE *o, heroes *hero, char* questTitle, int questPowerRequirement, int questExp, int numberOfHeroes, int letter[], int *totalExp)
{
    int groupPower=1;
    bool ok=true;
    char group[400]="\n";
    for(int i=0; i<numberOfHeroes; i++)
    {
        if(hero[i].Class=='D')
        {
            if(letter[0]!=0)
            {
                letter[0]--;
                groupPower+=hero[i].power;
                strcat(group, hero[i].name);
                strcat(group, ", ");
            }
        }

        if(hero[i].Class=='H')
        {
            if(letter[1]!=0)
            {
                letter[1]--;
                groupPower+=hero[i].power;
                strcat(group, hero[i].name);
                strcat(group, ", ");
            }
        }
        if(hero[i].Class=='T')
        {
            if(letter[2]!=0)
            {
                letter[2]--;
                groupPower+=hero[i].power;
                strcat(group, hero[i].name);
                strcat(group, ", ");
            }
        }
    }
    if(letter[0]>=1)
    {
        printFailture(o, questTitle, 'D');
        ok=false;
    }
    if(letter[1]>=1)
    {
        printFailture(o, questTitle, 'H');
        ok=false;
    }
    if(letter[2]>=1)
    {
        printFailture(o, questTitle, 'T');
        ok=false;
    }
    if(groupPower<questPowerRequirement)
    {
        fprintf(o, "\n\nNo group powerful enough is present to complete \"%s\"\n", questTitle);
        ok=false;
    }
    if(ok)
    {
        printVictory(o, group, questTitle, questPowerRequirement, groupPower, questExp);
        totalExp+=questExp;
    }
}


int determineIfQuestIsDoable(FILE *o, heroes *hero, quests *quest, int numberOfQuests, int numberOfHeroes, int *totalExp)
{
    int letter[3]={0,0,0};
    int groupExp;
    for(int i=0; i<numberOfQuests; i++)
    {
        groupExp=0;
        countClasses(quest[i].reqClass, letter);
        checkAvailabilityAndPower(o, hero, quest[i].title, quest[i].reqPow, quest[i].exp, numberOfHeroes, letter, &totalExp);
    }
}



int main()
{
    FILE *f=fopen("heroes.txt","r");
    FILE *g=fopen("quests.txt","r");
    FILE *o=fopen("outcome.txt","w");

    int numberOfHeroes=0, numberOfQuests=0, totalExp=0;
    while(1)
    {
        int tester=fgetc(f);
        if(tester==EOF || tester=='\n')
        {
            numberOfHeroes++;
            if(tester==EOF)
            {
                break;
            }
        }
    }
    rewind(f);

    while(1)
    {
        int tester=fgetc(g);
        if(tester==EOF || tester=='\n')
        {
            numberOfQuests++;
            if(tester==EOF)
            {
                break;
            }
        }
    }
    rewind(g);

    heroes *hero=(heroes*)malloc(sizeof(heroes)*numberOfHeroes);
    quests *quest=(quests*)malloc(sizeof(quests)*numberOfQuests);
    for(int i=0; i<numberOfHeroes; i++)
    {
        initializeHeroes(&hero[i]);
    }

    for(int i=0; i<numberOfQuests; i++)
    {
        initializeQuests(&quest[i]);
    }

    attributeHeroDetails(hero, f, numberOfHeroes);
    attributeQuestDetails(quest, g, numberOfQuests);

    sortHeroesByPower(hero, numberOfHeroes);

    for(int i=0; i<numberOfHeroes; i++)
    {
        printf("%s", hero[i].name);
    }

    determineIfQuestIsDoable(o, hero, quest, numberOfQuests, numberOfHeroes, &totalExp);

    fclose(f);
    fclose(g);
    fclose(o);
    return 0;
}
