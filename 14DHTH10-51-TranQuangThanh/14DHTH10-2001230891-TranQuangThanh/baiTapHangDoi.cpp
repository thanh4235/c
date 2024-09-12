#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char maDinhDanh[100];
    char hoTen[100];
    int namSinh;
}congDan;

struct queueNode {
    congDan info;
    queueNode* next;
};

struct queue {
    queueNode* head;
    queueNode* tail;
};

void initQueue(queue &q){
    q.head = NULL;
    q.tail = NULL;
}

int isEmpty(queue q) {
    return q.head == NULL;
}

void insert(queue &q,congDan c){
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->info = c;
    newNode->next = NULL;
    
    if(2024 - c.namSinh >= 70){
        newNode->next = q.head;
        q.head = newNode;
        if (q.tail == NULL) {
            q.tail = newNode;
        }
    }
    else if(isEmpty(q)){
        q.head=q.tail=newNode;
    }
    else{
        q.tail->next=newNode;
        q.tail=newNode;
    }
}

void terminate(queue &q){
    if(isEmpty(q)){
        printf("Hang doi rong!\n");
        return;
    }
    queueNode* temp=q.head;
    q.head=q.head->next;
    if(q.head==NULL){
        q.tail=NULL;
    }
    free(temp);
}

int countAll(queue q){
    int count=0;
    queueNode* temp = q.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int remaining(queue q, char* name){
    int position = 0;
    queueNode* temp = q.head;
    while (temp != NULL) {
        if (strcmp(temp->info.hoTen, name) == 0) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1;
}

int checkAge(queue q){
    queueNode* temp = q.head;
    while (temp != NULL) {
        if (2024 - temp->info.namSinh >= 70) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int checkName(queue q, char* name){
    queueNode* temp = q.head;
    while (temp != NULL) {
        if (strcmp(temp->info.hoTen, name) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void traverseAll(queue q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }
    int count=1;
    queueNode* temp = q.head;
    while (temp != NULL) {
        printf("%d/ Ma dinh danh: %s, Ho ten: %s, Nam sinh: %d\n",
               count, temp->info.maDinhDanh, temp->info.hoTen, temp->info.namSinh);
        temp = temp->next;
        count++;
    }
}

void showMenu() {
    printf("\n****************************************************************");
    printf("\n*                             MENU                             *");
    printf("\n*==============================================================*");
    printf("\n* 1: Them moi mot cong dan vao hang doi                        *");
    printf("\n* 2: Cho mot cong dan ra khoi hang doi                         *");
    printf("\n* 3: Xuat thong tin cua cong dan dau hang doi                  *");
    printf("\n* 4: Xuat tat ca cong dan trong hang doi                       *");
    printf("\n* 5: Tinh tong so cong dan trong hang doi                      *");
    printf("\n* 6: Tim so cong dan phai doi truoc khi den luot mot cong dan  *");
    printf("\n* 7: Kiem tra trong hang doi co nguoi >= 70 tuoi khong         *");
    printf("\n* 8: Kiem tra trong hang doi co cong dan ten Nguyen Hong Nhung *");
    printf("\n* 0: Ket thuc chuong trinh                                     *");
    printf("\n****************************************************************");
}

void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}

int main() {
    queue q;
    initQueue(q);

    int choice;
    do {
        showMenu();
        printf("\nChon chuc nang: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                congDan c;
                printf("\nNhap ma dinh danh: ");
                fgets(c.maDinhDanh, sizeof c.maDinhDanh, stdin);
    terminateNewLine(c.maDinhDanh);
                printf("Nhap ho ten: ");
                fgets(c.hoTen, sizeof c.hoTen, stdin);
    terminateNewLine(c.hoTen);
                printf("Nhap nam sinh: ");
                scanf("%d", &c.namSinh);
                insert(q, c);
                break;
            }
            case 2:
                terminate(q);
                break;
            case 3:
                if (!isEmpty(q)) {
                    printf("Cong dan dau hang doi: Ma dinh danh: %s, Ho ten: %s, Nam sinh: %d\n",
                           q.head->info.maDinhDanh, q.head->info.hoTen, q.head->info.namSinh);
                } else {
                    printf("Hang doi rong!\n");
                }
                break;
            case 4:
                traverseAll(q);
                break;
            case 5:
                printf("So luong cong dan trong hang doi: %d\n", countAll(q));
                break;
            case 6: {
                char name[100];
                printf("Nhap ho ten cong dan: ");
                scanf(" %[^\n]%*c", name);
                int position = remaining(q, name);
                if (position >= 0) {
                    printf("Cong dan %s phai doi %d cong dan.\n", name, position);
                } else {
                    printf("Cong dan %s khong co trong hang doi.\n", name);
                }
                break;
            }
            case 7:
                if (checkAge(q)) {
                    printf("Trong hang doi co nguoi gia.\n");
                } else {
                    printf("Trong hang doi khong co nguoi gia.\n");
                }
                break;
            case 8:
                if (checkName(q, "Nguyen Hong Nhung")) {
                    printf("Trong hang doi co cong dan ten: Nguyen Hong Nhung.\n");
                } else {
                    printf("Trong hang doi khong co cong dan ten: Nguyen Hong Nhung.\n");
                }
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}