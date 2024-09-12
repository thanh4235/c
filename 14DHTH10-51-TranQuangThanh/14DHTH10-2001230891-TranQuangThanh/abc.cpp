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

float trungBinhCong(list sl, float x){
    node* temp=sl.head;
    float tong=0;
    int dem=0;
    while(temp!=NULL){
        if(temp->info>x){
            tong+=temp->info;
            ++dem;
        }
        temp=temp->next;
    }
    if(dem==0) return 0;
    return (tong/dem);
}

int main() {
    list sl;
    initList(sl);

    // Thêm các phần tử vào danh sách
    insertTail(sl, createNode(7));
    insertTail(sl, createNode(1));
    insertTail(sl, createNode(4));
    insertTail(sl, createNode(5));
    insertTail(sl, createNode(2));

    int x;
    printf("\nNhap x: ");
    scanf("%d",&x);

    printf("\nTrung binh cong: %f",trungBinhCong(sl,x));

    return 0;
}
