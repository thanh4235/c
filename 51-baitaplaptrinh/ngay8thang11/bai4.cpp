#include <stdio.h>
int main()
{
    int a, b;
    do
    {
        printf("Số điện (kw): ");
        scanf("%d", &a);
        if (a < 0)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (a < 0);
    if (a < 50)
        b = a * 1200;
    else if (a > 50 && a <= 100)
        b = 50 * 1200 + (a - 50) * 1500;
    else
        b = 50 * 1200 + 50 * 1500 + (a - 100) * 2000;
    printf("Tổng tiền: %d VND", b);
}