#include <stdio.h>

struct node
{
    int info;
    node *next;
};

struct list
{
    node *head;
    node *tail;
};

node *createNode(int x)
{
    node *newNode = new node;
    if (newNode == NULL)
    {
        printf("\nKHONG DU BO NHO\n");
        return NULL;
    }
    newNode->info = x;
    newNode->next = NULL;
    return newNode;
}

void initList(list &l)
{
    l.head = NULL;
    l.tail = NULL;
}

int isEmpty(list l)
{
    if (l.head == NULL)
        return 1;
    else
        return 0;
}

int insertHead(list &l, node *p)
{
    if (p == NULL)
        return 0;
    if (isEmpty(l) == 1)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
    return 1;
}

int insertTail(list &l, node *p)
{
    if (p == NULL)
        return 0;
    if (isEmpty(l) == 1)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
    return 1;
}

int deleteHead(list &l, int &x)
{
    if (isEmpty(l) == 1)
        return 0;
    node *p = l.head;
    l.head = l.head->next;
    if (l.head == NULL)
        l.tail = NULL;
    x = p->info;
    delete p;
    return 1;
}

int deleteTail(list &l, int &x)
{
    if (isEmpty(l) == 1)
        return 0;
    node *p = l.tail;
    node *q = l.head;
    if (p == q)
        l.head = l.tail = NULL;
    else
    {
        while (q->next != p)
            q = q->next;
        l.tail = q;
        l.tail->next = NULL;
    }
    x = p->info;
    delete p;
    return 1;
}

bool check(int x)
{
    if (x < 0 && x == 1 && x == 2)
        return false;
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void traverseList(list l)
{
    node *currentNode = l.head; // Bắt đầu từ nút đầu tiên

    // Duyệt qua từng nút trong danh sách liên kết
    while (currentNode != NULL)
    {
        // In ra giá trị của nút hiện tại
        printf("%d ", currentNode->info);

        // Di chuyển đến nút tiếp theo trong danh sách
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main()
{
    list l;
    initList(l);
    insertHead(l, createNode(2));
    insertHead(l, createNode(3));
    insertHead(l, createNode(4));
    insertHead(l, createNode(5));
    traverseList(l);
    for (node *i = l.head; i != NULL; i = i->next)
    {
        if (check(i->info))
    }
}