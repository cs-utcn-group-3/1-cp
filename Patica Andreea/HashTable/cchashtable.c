#include "cchashtable.h"
#include "common.h"
#include <string.h>

#define TABLE_SIZE    10000
#define MULTIPLIER    37

int HtCreate(CC_HASH_TABLE **HashTable)
{
    CC_HASH_TABLE* ht = NULL;

    CC_UNREFERENCED_PARAMETER(HashTable);

    if (NULL == HashTable)
    {
        return -1;
    }

    ht = (CC_HASH_TABLE*)malloc(sizeof(CC_HASH_TABLE)*TABLE_SIZE);
    if (NULL == ht)
    {
        return -1;
    }

    memset(ht, 0, sizeof(*ht));
    
    *HashTable = ht;

    return 0;
}

int HtDestroy(CC_HASH_TABLE **HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    return -1;
}

int HtSetKeyValue(CC_HASH_TABLE *HashTable, char *Key, int Value)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);
    CC_UNREFERENCED_PARAMETER(Value);
/*
    if (NULL == HashTable)
    {
        return -1;
    }
    if (NULL == Key)
    {
        return -1;
    }
    if (NULL == Value)
    {
        return -1;
    }

    unsigned const char* us;
    us = (unsigned const char*) Key;
    int hashIndex = 0;
    while (*us != '\0')
    {
        hashIndex = hashIndex * MULTIPLIER + *us;
        us++;
    }

    hashIndex %= TABLE_SIZE;

    while (HashTable[hashIndex] != NULL && HashTable[hashIndex]->Key != NULL)
    {
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }*/
    return -1;
}

int HtGetKeyValue(CC_HASH_TABLE *HashTable, char *Key, int *Value)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);
    CC_UNREFERENCED_PARAMETER(Value);
    return -1;
}

int HtRemoveKey(CC_HASH_TABLE *HashTable, char *Key)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);
    return -1;
}

int HtHasKey(CC_HASH_TABLE *HashTable, char *Key)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);
    return -1;
}

int HtGetFirstKey(CC_HASH_TABLE* HashTable, CC_HASH_TABLE_ITERATOR **Iterator, char **Key)
{
    CC_HASH_TABLE_ITERATOR *iterator = NULL;

    CC_UNREFERENCED_PARAMETER(Key);

    if (NULL == HashTable)
    {
        return -1;
    }
    if (NULL == Iterator)
    {
        return -1;
    }
    if (NULL == Key)
    {
        return -1;
    }

    iterator = (CC_HASH_TABLE_ITERATOR*)malloc(sizeof(CC_HASH_TABLE_ITERATOR));
    if (NULL == iterator)
    {
        return -1;
    }

    memset(iterator, 0, sizeof(*iterator));

    iterator->HashTable = HashTable;
    // INITIALIZE THE REST OF THE FIELDS OF iterator

    *Iterator = iterator;

    // FIND THE FIRST KEY AND SET Key

    return 0;
}

int HtGetNextKey(CC_HASH_TABLE_ITERATOR *Iterator, char **Key)
{
    CC_UNREFERENCED_PARAMETER(Key);
    CC_UNREFERENCED_PARAMETER(Iterator);
    return -1;
}

int HtReleaseIterator(CC_HASH_TABLE_ITERATOR **Iterator)
{
    CC_UNREFERENCED_PARAMETER(Iterator);
    return -1;
}

int HtClear(CC_HASH_TABLE *HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    return -1;
}

int HtGetKeyCount(CC_HASH_TABLE *HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    return -1;
}
