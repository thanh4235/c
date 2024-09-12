#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
struct hashNode
{
    int key;
    hashNode *next;
};
hashNode *bucket[MAXSIZE];

int hashFunction(int key)
{
    return (key % MAXSIZE);
}

int search(int k)
{
    int b = hashFunction(k);
    hashNode *p = bucket[b];
    while (k > p->key && p != NULL)
        p = p->next;
    if (p == NULL || k != p->key)
        return -1;
    else
        return b;
}

void insertAfter(hashNode *p, int k)
{
    if (p == NULL)
        printf("Khong them vao Node moi duoc");
    else
    {
        hashNode *q = new hashNode;
        q->key = k;
        q->next = p->next;
        p->next = q;
    }
}

void push(int b, int x)
{
    hashNode *p = new hashNode;
    p->key = x;
    p->next = bucket[b];
    bucket[b] = p;
}

// tac vu nay chi su dung khi them vao mot bucket co thu tu
void place(int b, int k)
{
    hashNode *p, *q;
    q = NULL;
    for (p = bucket[b]; p != NULL && k > p->key; p = p->next)
        q = p;
    if (q == NULL)
        push(b, k);
    else
        insertAfter(q, k);
}
// them mot Node co khoa la k vao trong bang bam
void insert(int k)
{
    int b = hashFunction(k);
    place(b, k);
}

int deleteAfter(hashNode *p)
{
    hashNode *q;
    int k;
    if (p == NULL || p->next == NULL)
    {
        printf("\nKhong xoa Node duoc");
        return 0;
    }
    q = p->next;
    k = q->key;
    p->next = q->next;
    delete q;
    return k;
}

int isEmptyBucket(int b)
{
    if (bucket[b] == NULL)
        return TRUE;
    else
        return FALSE;
}

int pop(int b)
{
    if (isEmptyBucket(b))
    {
        printf("Bucket %d bi rong, khong xoa duoc", b);
        return 0;
    }
    hashNode *p = bucket[b];
    int k = p->key;
    bucket[b] = p->next;
    delete p;
    return k;
}

void traverseBucket(int b)
{
    hashNode *p = bucket[b];
    while (p != NULL)
    {
        printf("%4d", p->key);
        p = p->next;
    }
}

void traverseHashTable()
{
    for (int b = 0; b < MAXSIZE; b++)
    {
        printf("\n Bucket[%d]=", b);
        traverseBucket(b);
    }
}

// Xoa mot phan tu co kkhoa k ra khoi bang bam
void remove(int k)
{
    int b;
    hashNode *p, *q;
    b = hashFunction(k);
    p = bucket[b];
    q = p;
    while (p != NULL && p->key != k)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        printf("\nKhong co Node co khoa la: %d", b);
    else if (p == bucket[b])
        pop(b);
    else
        deleteAfter(q);
}

void initHashTable()
{
    for (int b = 0; b < MAXSIZE; b++)
        bucket[b] = NULL;
}

void showMenu()
{
    printf("\n**********************************");
    printf("\n*              MENU              *");
    printf("\n*--------------------------------*");
    printf("\n* 1: Them mot nut vao bang       *");
    printf("\n* 2: Xoa mot nut trong bang bam  *");
    printf("\n* 3: Duyet bang bam              *");
    printf("\n* 4: Tim kiem tren bang bam      *");
    printf("\n* 0: Ket thuc chuong trinh       *");
    printf("\n**********************************");
}

void process()
{
    int b, n, key, selectFunction;
    initHashTable();
    do
    {
        showMenu();
        printf("\n Chuc nang ban chon: ");
        scanf("%d", &selectFunction);
        switch (selectFunction)
        {
        case 1:
            printf("\n Nhap gia tri khoa muon them: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("\n Xoa mot nut tren bang bam");
            printf("\n Nhap vao khoa muon xoa: ");
            scanf("%d", &key);
            remove(key);
            break;
        case 3:
            printf("\n Duyet bang bam");
            traverseHashTable();
            break;
        case 4:
            printf("\n Tim kiem mot khoa tren bang bam");
            printf("\n Nhap khoa can tim: ");
            scanf("%d", &key);
            b = search(key);
            if (b == -1)
                printf("\n Khong thay");
            else
                printf("\n Tim thay trong bucket %d", b);
            break;
        }
    } while (selectFunction != 0);
}

int main()
{
    process();
    return 0;
}