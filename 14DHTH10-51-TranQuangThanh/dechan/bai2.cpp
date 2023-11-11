#include <stdio.h>
#include <conio.h>
int main()
{
    int n, tong = 0, dem = 0;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &n);
        if (n < 0 || n % 5 != 0)
            printf("Dieu kien: so  nguyen duong va chia het cho 5\n");
    } while (n < 0 || n % 5 != 0);

    for (int i = 1; i <= n; i += 2)
        tong = tong + i;
    printf("Tong cac so le tu 1 den %d la %d\n", n, tong);

    while (n >= 10)
    {
        n = n / 10;
        dem++;
    }

    printf("Co %d chu so", dem + 1);

    getch();
    return 0;
}