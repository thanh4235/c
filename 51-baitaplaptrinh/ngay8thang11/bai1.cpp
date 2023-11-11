#include <stdio.h>
int main()
{
    int a, b, c;
    do
    {
        printf("Nhập năm sinh: ");
        scanf("%d", &a);
        if (a < 0)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (a < 0);
    do
    {
        printf("Nhập năm hiện tại: ");
        scanf("%d", &b);
        if (b < a)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (b < a);
    c = b - a;
    if (c >= 30)
        printf("thưởng 3 triệu");
    else if (c >= 18 && c < 30)
        printf("Thưởng 2 triệu");
    else
        printf("Thưởng 1 triệu");
}