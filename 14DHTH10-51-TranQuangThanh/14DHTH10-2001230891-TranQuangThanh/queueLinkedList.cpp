#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
    int info;
    queueNode *next;
};
struct queue
{
    queueNode *head;
    queueNode *tail;
};

void initQueue(queue &q)
{
    q.head = NULL;
    q.tail = NULL;
}

queueNode *makeNode(int x)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->info = x;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(queue q) // Queue có rỗng hay không
{                    // Hàm trả về 1: nếu Queue rỗng, và 0; nếu Queue khác rỗng
    if (q.head == NULL)
        return 1; // Nếu queue rỗng
    else
        return 0; // Nếu queue không rỗng
}

int insertQueue(queue &q, queueNode *p)
{
    if (p == NULL)
        return 0; // Thực hiện không thành công
    if (isEmpty(q) == 1)
    {
        q.head = p;
        q.tail = p;
    }
    else
    {
        q.tail->next = p;
        q.tail = p;
    }
    return 1; // Thực hiện thành công
}

int deleteQueue(queue &q, int &x)
{
    if (isEmpty(q) == 1)
        return 0; // Thực hiện không thành công
    queueNode *p = q.head;
    q.head = q.head->next;
    if (q.head == NULL)
        q.tail = NULL;
    x = p->info; // Lấy thông tin của nút bị hủy
    delete p;    // Hủy nút do p trỏ đến
    return 1;    // Thực hiện thành công
}

int getHead(queue q, int &x)
{
    if (isEmpty(q) == 1)
        return 0;     // Thực hiện không thành công
    x = q.head->info; // Lấy thông tin của nút ở đầu queue
    return 1;         // Thực hiện thành công
}

int getTail(queue q, int &x)
{
    if (isEmpty(q) == 1)
        return 0;     // Thực hiện không thành công
    x = q.tail->info; // Lấy thông tin của nút ở cuối queue
    return 1;         // Thực hiện thành công
}

void showQueue(queue q)
{
    if (isEmpty(q) == 1)
    {
        printf("\nHàng đợi rỗng!");
        return; // thực hiện không thành công
    }
    printf("\nNội dung hàng đợi là:");
    for (queueNode *p = q.head; p != NULL; p = p->next)
        printf(" %d", p->info);
}

int main()
{
    queue q;
    initQueue(q);

    int choice, x;
    queueNode *p;

    while (true)
    {
        printf("\n======== MENU ========\n");
        printf("Thêm phần tử vào hàng đợi (1)\n");
        printf("Xóa phần tử khỏi hàng đợi (2)\n");
        printf("Hiển thị phần tử ở đầu hàng đợi (3)\n");
        printf("Hiển thị phần tử ở cuối hàng đợi (4)\n");
        printf("Hiển thị toàn bộ hàng đợi (5)\n");
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
            printf("\nNhập giá trị cần thêm vào hàng đợi: ");
            scanf("%d", &x);
            p = makeNode(x);
            if (insertQueue(q, p))
                printf("Đã thêm vào hàng đợi thành công!");
            else
                printf("Thêm vào hàng đợi không thành công!");
            break;
        case 2:
            if (deleteQueue(q, x))
                printf("Đã xóa phần tử %d khỏi hàng đợi!", x);
            else
                printf("Hàng đợi rỗng! Không thể xóa!");
            break;
        case 3:
            if (getHead(q, x))
                printf("Phần tử ở đầu hàng đợi là: %d", x);
            else
                printf("Hàng đợi rỗng!");
            break;
        case 4:
            if (getTail(q, x))
                printf("Phần tử ở cuối hàng đợi là: %d", x);
            else
                printf("Hàng đợi rỗng!");
            break;
        case 5:
            showQueue(q);
            break;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    }
    return 0;
}