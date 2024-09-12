#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node *makeNode(int x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void pushFront(node **head, int x){
    node *newNode=makeNode(x);
    newNode->next=*head;
    if(*head!=NULL)
    (*head)->prev=newNode;
    *head=newNode;
}

void pushBack(node **head, int x){
    node *newNode=makeNode(x);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

int sizeOfList(node *head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

void insert(node **head, int x, int k){
    node *newNode=makeNode(x);

    int size=sizeOfList(*head);
    if(k<1||k>size){
        printf("NONNNNNNNNNNNNN\n");
        return;
    }
    if(k==1){
        pushFront(head,x);
        return;
    }
    node *temp=*head;
    for(int i=0;i<k-1;i++){
        temp=temp->next;
    }
    node *a=temp->prev;
    a->next=newNode;
    newNode->prev=a;
    newNode->next=temp;
    temp->prev=newNode;
}

void output(node *head){
    while(head!=NULL){
        printf(" %d",head->data);
        head=head->next;
    }
}

int main(){
    node *head=NULL;

    pushFront(&head,-5);
    pushFront(&head,0);
    pushFront(&head,5);
    pushFront(&head,10);
    pushFront(&head,15);

    insert(&head,100,3);

    output(head);
}

/*Chen vao giua
while(temp->next!=NULL){
        temp=temp->next;
    }
    node *a=temp->prev;
    a->next=newNode;
    newNode->prev=a;
    newNode->next=temp;
    temp->prev=newNode;
    */