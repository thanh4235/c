#include <stdio.h>
int main()
{
    int i, n, tong = 0;
    do
    {
        printf("Nhập n: ");
        scanf("%d", &n);
        if (n < 0)
            printf("Vui lòng nhập lại!!");
    } while (n < 0);
    for (i = 1; i <= n; i++)
        tong = tong + i;

    printf("Tổng các số tự nhiên nhỏ hơn %d: %d", n, tong);
}