#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NULLKEY -1
#define MAXSIZE 100

struct hashNode
{
    int key;
};
hashNode hashTable[MAXSIZE];
int n;

int hashFunction(int key)
{
    return (key % MAXSIZE);
}

void initalize()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        hashTable[i].key = NULLKEY;
    }
    n = 0;
}

int isEmpty()
{
    if (n == 0)
        return TRUE;
    else
        return FALSE;
}

int isFull()
{
    if (n == MAXSIZE - 1)
        return TRUE;
    else
        return FALSE;
}

int search(int k)
{
    int i = hashFunction(k);
    while (hashTable[i].key != k && hashTable[i].key != NULLKEY)
    {
        i = i + 1;
        if (i >= MAXSIZE)
            i = i - MAXSIZE;
    }
    if (hashTable[i].key == k)
        return i;
    else
        return MAXSIZE;
}

int insert(int k)
{
    if (isFull())
    {
        printf("\n Bang bam bi day, khong them vao duoc");
        return MAXSIZE;
    }
    int i = hashFunction(k);
    while (hashTable[i].key != NULLKEY)
    {
        i++;
        if (i >= MAXSIZE)
            i = i - MAXSIZE;
    }
    hashTable[i].key = k;
    n++;
    return i;
}

void viewTable()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("\n Table[%2d]: %4d", i, hashTable[i].key);
    }
}