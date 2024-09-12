#include <stdio.h>
#include <stdlib.h>

#define max 100 // Định nghĩa kích thước tối đa của stack

struct stack
{
    int top;       // Đỉnh top
    int data[max]; // Mảng các phần tử
};

// Hàm khởi tạo stack
void initializeStack(stack &s)
{
    s.top = -1; // ngăn xếp s rỗng khi s.top=-1 (ngược lại, ngăn xếp s đầy khi s.top=max)
}

// Hàm thêm
void push(stack &s, int x)
{
    if (s.top == max - 1)
    {
        printf("Stack đã đầy!\n");
        return;
    }
    s.top++;
    s.data[s.top] = x;
}

// Hàm xóa
void pop(stack &s)
{
    if (s.top == -1)
    {
        printf("Stack rỗng!\n");
        return;
    }
    s.top--;
    printf("Đã xóa\n");
}

// Hàm in ra giá trị ở đỉnh của stack
void peek(stack s)
{
    if (s.top == -1)
    {
        printf("Stack rỗng!\n");
        return;
    }
    printf("In ra giá trị ở đỉnh stack: %d\n", s.data[s.top]);
}

// in ra có bao nhiêu phần tử trong stack
void size(stack s)
{
    printf("Có tổng cộng %d phần tử trong stack\n", s.top + 1);
}

// Hàm in hết các giá trị trong stack
void output(stack s)
{
    printf("\nIn ra:");
    for (int i = s.top; i >= 0; i--)
    {
        printf(" %d", s.data[i]);
    }
}

int main()
{
    stack s;
    initializeStack(s);

    // lập menu
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
            push(s, data);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            peek(s);
            break;
        case 4:
            size(s);
            break;
        case 5:
            output(s);
            break;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    }
    return 0;
}