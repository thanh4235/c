#include <stdio.h>
int main()
{
    int a, b = 0, tong = 0;
    do
    {
        printf("Nhập số nguyên dương n bất kì: ");
        scanf("%d", &a);
        if (a < 0)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (a < 0);
    for (int i = 1; i <= a; i++)
        if (a % i == 0)

            tong = tong + i;

    printf("Tổng các ước số dương của %d là %d", a, tong);
}