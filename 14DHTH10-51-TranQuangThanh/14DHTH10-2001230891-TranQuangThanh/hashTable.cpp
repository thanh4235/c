#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NULLKEY -1
#define MAXSIZE 100
struct hashNode
{
    int key;
    int next;
};

hashNode hashTable[MAXSIZE];
int avail;

void initialize()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        hashTable[i].key = NULLKEY;
        hashTable[i].next = -1;
    }
    avail = MAXSIZE - 1;
}

int isEmpty()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (hashTable[i].key != NULLKEY)
            return FALSE;
    }
    return TRUE;
}

int search(int k)
{
    int i = hashFunction(k);
    while (k != hashTable[i].key && i != 1)
        i = hashTable[i].next;
    if (k == hashTable[i].key)
        return i;
    else
        return MAXSIZE;
}

int getEmpty()
{
    while (hashTable[avail].key != NULLKEY)
        avail--;
    return avail;
}

int insert(int k)
{
    int i, j;
    i = search(k);
    if (i != MAXSIZE)
    {
        printf("\nkhoa %d b trung, khong them vao duoc", k);
        return i;
    }
    i = hashFunction(k);
    while (hashTable[i].next >= 0)
        i = hashTable[i].next;
    if (hashTable[i].key == NULLKEY)
        j = i;
    else
    {
        j = getEmpty();
        if (j < 0)
        {
            printf("\n Bang bam bi day khong them vao duoc");
            return j;
        }
        else
        {
            hashTable[i].next = j;
        }
    }
    hashTable[j].next = k;
    return j;
}

void viewTable()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("\nTable[%2d]: %4d %4d", i, hashTable[i].key, hashTable[i].next);
    }
}