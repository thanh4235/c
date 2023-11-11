#include <stdio.h>
int main()
{
    int a, b, c;
    do
    {
        printf("Nhập số ngày làm: ");
        scanf("%d", &a);
        if (a < 0)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (a < 0);
    do
    {
        printf("Nhập đơn giá ngày: ");
        scanf("%d", &b);
        if (b < 0)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (b < 0);
    if (a < 20)
        c = a * b;
    else
        c = (20 * b) + ((a - 20) * (b * 2));
    printf("Tổng tiền: %d", c);
}