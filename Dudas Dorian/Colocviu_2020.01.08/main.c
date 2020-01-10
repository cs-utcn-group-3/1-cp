#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 30
#define MAX_QUEST_TITLE_LENGTH 50

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
        printf("%s\n",quest[i].title);
        p=strtok(NULL,",\n");
        strcpy(quest[i].reqClass,p);
        printf("%s\n",quest[i].reqClass);
        p=strtok(NULL,",\n");
        quest[i].reqPow=0;
        for(int j=0; j<strlen(p); j++)
        {
            quest[i].reqPow=quest[i].reqPow*10+(p[j]-'0');
        }
        printf("%d\n",quest[i].reqPow);
        p=strtok(NULL,",\n");
        quest[i].exp=0;
        for(int j=0; j<strlen(p); j++)
        {
            quest[i].exp=quest[i].exp*10+(p[j]-'0');
        }
        printf("%d\n",quest[i].exp);
    }
}

/*int isClassTheSame(heroes *hero, quests *quest)
{
    static int HeroNr=0;
    for(int i=0; i<; i++)
    {
        printf("%s",quest[i].reqClass);
    }



}*/

/*int determineIfQuestIsDoable(heroes *hero, quests *quest)
{
    int status=0; //failed
    for(int i=0; i<; i++)
    {

    }
}*/

/*void printVictory()
{
    printf("%s went on to complete %s - SUCCESS (%d vs %d) and gained %d xp", );
}


void printFailture()
{
    printf("Cannot execute mission %s not enough heroes of type %c", quest.title, );
}*/


int main()
{
    FILE *f=fopen("heroes.txt","r");
    FILE *g=fopen("quests.txt","r");
    //FILE *o=fopen("outcome.txt","w");

    int numberOfHeroes=0, numberOfQuests=0;
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
    //determineIfQuestIsDoable(hero, quest);
    //isClassTheSame(hero, quest);

    fclose(f);
    fclose(g);
    //fclose(o);
    return 0;
}
