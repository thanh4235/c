#include <stdio.h>

#define max 100

struct queue
{
    int info[max];
    int n = 0;
    int head = -1;
    int tail = -1;
};

// Khởi tạo queue
void initQueue(queue &q)
{
    q.n = 0;
    q.head = -1;
    q.tail = -1;
}

// Kiểm tra queue rỗng
int isEmpty(queue q) // Kiểm tra queue có rỗng hay không?
{                    // Hàm trả về 1: nếu queue rỗng, và 0: nếu queue khác rỗng
    if (q.n == 0)
        return 1; // Nếu queue rỗng
    else
        return 0; // Nếu queue không rỗng
}

// Kiểm tra queue đầy
int isFull(queue q) // Kiểm tra queue có đầy thật hay không?
{                   // Hàm trả về 1: nếu queue đầy, và 0: nếu queue chưa đầy
    if (q.n == max)
        return 1;
    else
        return 0;
}

// Thêm một phần tử mới vào cuối queue
int insertQueue(queue &q, int x)
{
    if (isFull(q) == 1)
        return 0; // Thực hiện không thành công
    if (q.head == -1)
    {
        q.head = 0;
        q.tail = -1;
    }
    q.tail = (q.tail + 1) % max;
    q.info[q.tail] = x;
    q.n++;
    return 1; // Thực hiện thành công
}

// Cách khác
int insertQueue2(queue &q, int x)
{
    int i, h, t;
    if (q.tail - q.head + 1 == max) // Queue đầy nên không thể thêm
        return 0;                   // Thực hiện không thành công
    if (q.head == -1)
    {
        q.head = 0;
        q.tail = -1;
    }
    if (q.tail == max - 1) // Queue đầy ảo
    {
        h = q.head;
        t = q.tail;
        for (i = h; i <= t; i++)
            q.info[i - h] = q.info[i];
        q.head = 0;
        q.tail = t - h;
    }
    q.n++;
    q.tail++;
    q.info[q.tail] = x;
    return 1; // Thực hiện thành công
}

int deleteQueue(queue &q, int &x)
{
    if (isEmpty(q) == 1)
        return 0; // Thực hiện không thành công
    x = q.info[q.head];
    q.head = (q.head + 1) % max;
    q.n--;
    return 1; // Thực hiện thành công
}

int deleteQueue2(queue &q, int &x)
{
    if (q.head == -1) // Queue rỗng
    {
        printf("Hàng đợi rỗng!");
        return 0; // Thực hiện không thành công
    }
    x = q.info[q.head]; // Lấy thông tin phần tử ở đầu queue
    q.head++;
    if (q.head > q.tail) // Trường hợp có 1 phần tử
    {
        q.head = -1;
        q.tail = -1;
    }
    return 1; // Thực hiện thành công
}

// Lấy giá trị ở phần tử đầu
int getHead(queue q, int &x)
{
    if (isEmpty(q) == 1) // Queue rỗng
    {
        printf("Queue rỗng!\n");
        return 0; // Thực hiện không thành công
    }
    x = q.info[q.head]; // Lấy thông tin của phần tử ở đầu queue
    return 1;           // Thực hiện thành công
}

// Lấy giá trị ở phần tử cuối
int getTail(queue q, int &x)
{
    if (isEmpty(q) == 1) // Queue rỗng
    {
        printf("Queue rỗng!\n");
        return 0; // Thực hiện không thành công
    }
    x = q.info[q.tail]; // Lấy thông tin của phần tử ở cuối Queue
    return 1;           // Thực hiện thành công
}

// Hàm in hết các giá trị trong queue
void showQueue(queue q)
{
    if (isEmpty(q) == 1)
    {
        printf("\nQueue rỗng!");
        return;
    }
    printf("\nIn ra:");
    for (int i = q.head; i != q.tail; i = (i + 1) % max)
    {
        int x = q.info[i];
        printf(" %d", x);
    }
    printf(" %d", q.info[q.tail]);
}

int main()
{
    queue q;
    // initQueue(q);

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

        int x, choice;
        printf("\nNhập lựa chọn: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\nThoát khỏi chương trình");
            return 0;
            break;
        case 1:
            printf("Nhập số bất kì: ");
            scanf("%d", &x);
            if (insertQueue(q, x))
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
            {
                printf("Phần tử ở đầu hàng đợi là: %d", x);
            }
            else
                printf("Hàng đợi rỗng!");
            break;
        case 4:
            if (getTail(q, x))
            {
                printf("Phần tử ở cuối hàng đợi là: %d", x);
            }
            else
                printf("Hàng đợi rỗng!");
            break;
        case 5:
            showQueue(q);
            break;
        default:
            printf("Lựa chọn không hợp lệ!\n");
        }
    }
    return 0;
}