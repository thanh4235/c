#include <stdio.h>
int main()
{
    int m, tong = 0;
    do
    {
        printf("Nhập số nguyên m: ");
        scanf("%d", &m);
        if (m < 0 || m % 5 != 0)
            printf("Điều kiện: số dương vả chia hết cho 5\n");
    } while (m < 0 || m % 5 != 0);
    for (int i = 1; i < m; i++)
        if (i % 2 == 0)
            tong = tong + 1;
    printf("Có %d số chẵn từ 1 đến %d", tong, m);
}