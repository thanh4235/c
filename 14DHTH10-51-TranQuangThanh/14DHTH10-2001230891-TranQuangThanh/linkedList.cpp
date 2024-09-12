#include <stdio.h>
#include <conio.h>

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
    node *p = new node;
    if (p == NULL)
    {
        printf("Không đủ bộ nhớ để cấp phát nút mới!");
        getch();
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
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

void bubbleSort(list &l) {
    int temp;
    for(node* i=l.head;i->next!=NULL;i=i->next){
        for(node* j=i->next;j!=NULL;j=j->next){
            if(i->info<j->info){
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
        }
    }
}

int main() {
    list l;
    initList(l);

    // Thêm các phần tử vào danh sách
    insertTail(l, createNode(7));
    insertTail(l, createNode(1));
    insertTail(l, createNode(4));
    insertTail(l, createNode(5));
    insertTail(l, createNode(2));

    printf("Danh sach truoc khi sap xep: \n");
    for (node* p = l.head; p != NULL; p = p->next) {
        printf("%d ", p->info);
    }

    // Sắp xếp danh sách
    bubbleSort(l);

    printf("\nDanh sach sau khi sap xep: \n");
    for (node* p = l.head; p != NULL; p = p->next) {
        printf("%d ", p->info);
    }

    // Xóa danh sách để tránh rò rỉ bộ nhớ
    int x;
    while (!isEmpty(l)) {
        deleteHead(l, x);
    }

    return 0;
}
