#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maDinhDanh[100];
    char hoTen[100];
    int namSinh;
} congDan;

typedef struct queueNode {
    congDan info;
    struct queueNode* next;
} queueNode;

typedef struct queue {
    queueNode* head;
    queueNode* tail;
} queue;

void initQueue(queue &q) {
    q.head = NULL;
    q.tail = NULL;
}

int isEmpty(queue q) {
    return q.head == NULL;
}

void insert(queue &q, congDan c) {
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->info = c;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q.head = q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

void terminate(queue &q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }
    queueNode* temp = q.head;
    q.head = q.head->next;
    if (q.head == NULL) {
        q.tail = NULL;
    }
    free(temp);
}

void traverseAll(queue q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }
    queueNode* temp = q.head;
    while (temp != NULL) {
        printf("Ma dinh danh: %s, Ho ten: %s, Nam sinh: %d\n",
               temp->info.maDinhDanh, temp->info.hoTen, temp->info.namSinh);
        temp = temp->next;
    }
}

int main() {
    queue q;
    initQueue(q);

    // Thêm công dân vào hàng đợi
    congDan c1 = {"123456789", "Nguyen Van A", 1985};
    insert(q, c1);

    congDan c2 = {"987654321", "Le Thi B", 1990};
    insert(q, c2);

    // Xuất thông tin hàng đợi hiện tại
    printf("Hàng đợi hiện tại:\n");
    traverseAll(q);

    // Loại bỏ một công dân ra khỏi hàng đợi
    terminate(q);

    // Xuất thông tin hàng đợi sau khi loại bỏ
    printf("\nHàng đợi sau khi loại bỏ một công dân:\n");
    traverseAll(q);

    return 0;
}
