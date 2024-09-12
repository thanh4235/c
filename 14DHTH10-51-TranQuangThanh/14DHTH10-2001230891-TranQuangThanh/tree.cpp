#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

void makeTree(node *&t){
    t=NULL;
}

void addNodeToTree(node *&t, int x){
    if(t==NULL){
        node *p=(node*)malloc(sizeof(node));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        t=p;
    }
    else if(t->data>x){
        addNodeToTree(t->left, x);
    }
    else if(t->data<x){
        addNodeToTree(t->right, x);
    }
}

void display(node *t){
    if(t!=NULL){
        printf("%d ",t->data);
        display(t->left);
        display(t->right);
    }
}

void menu(node *&t){
    while(true){
        printf("\n======== MENU ========\n");
        printf("Nhap du lieu (1)\n");
        printf("Xuat du lieu cay (2)\n");
        printf("Ket thuc (0)\n");
        printf("=======================\n");
    int choice;
    printf("\nNhap lua chon: ");
    scanf("%d",&choice);
    if(choice<0||choice>2){
        printf("\nLua chon khong hop le");
        system("pause");
    }
    else if(choice==1){
        int x;
        printf("Nhap so nguyen x: ");
        scanf("%d",&x);
        addNodeToTree(t,x);
    }
    else if(choice==2){
        printf("DUYET CAY THEO NLR\n");
        display(t);
    }
    else{
        break;
    }
    }
}

int main(){
node *t;
makeTree(t);
menu(t);
system("pause");
return 0;
}

