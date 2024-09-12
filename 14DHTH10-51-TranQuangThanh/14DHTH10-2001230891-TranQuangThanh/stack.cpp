#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node *next;
};

typedef struct node node;

node *makeNode(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(node **top, int x)
{
    node *newNode = makeNode(x);
    newNode->next = *top;
    *top = newNode;
}

void pop(node **top)
{
    if (*top == NULL)
    {
        printf("Stack rỗng\n");
        return;
    }
    node *temp = *top;
    *top = (*top)->next;
    temp->next = NULL;
    free(temp);
    printf("Đã xóa\n");
}

void peek(node *top)
{
    if (top == NULL)
    {
        printf("Stack rỗng\n");
        return;
    }
    printf("Giá trị đỉnh của stack: %d\n", top->data);
}

void size(node *top)
{
    int count = 0;
    while (top != NULL)
    {
        top = top->next;
        count++;
    }
    printf("Kích thước: %d\n", count);
}

void output(node *top)
{
    printf("\nIn ra:");
    while (top != NULL)
    {
        printf(" %d", top->data);
        top = top->next;
    }
}

int main()
{
    node *top = NULL;

    while (true)
    {
        printf("\n======== MENU ========\n");
        printf("Nhập (1)\n");
        printf("Xóa (2)\n");
        printf("Giá trị đỉnh của stack (3)\n");
        printf("Kích thước (4)\n");
        printf("Xuất (5)\n");
        printf("Kết thúc (0)\n");
        printf("=======================\n");

        int choice;
        printf("\nNhập lựa chọn: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Thoát khỏi chương trình!\n");
            exit(0);
        case 1:
            printf("Nhập giá trị muốn thêm vào stack: ");
            int data;
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            size(top);
            break;
        case 5:
            output(top);
            break;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    }
    return 0;
}