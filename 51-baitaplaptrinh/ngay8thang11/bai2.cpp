#include <stdio.h>
int main()
{
    int a, tong = 0;
    do
    {
        printf("Nhập 1 số nguyên chẵn bất kì: ");
        scanf("%d", &a);
        if (a % 2 != 0)
            printf("Lỗi!! Vui lòng nhập lại\n");
    } while (a % 2 != 0);

    for (int i = 1; i <= a; i++)
        tong = tong + i;

    printf("Tổng từ 1 đến %d: %d\n", a, tong);
}