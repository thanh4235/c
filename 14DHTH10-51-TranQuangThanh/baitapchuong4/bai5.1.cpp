#include <stdio.h>
int dk(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int x, dem = 0;
    do
    {
        printf("Nhap x: ");
        scanf("%d", &x);
        if (x <= 0)
            printf("Vui long nhap so lon hon 0!!\n");
    } while (x <= 0);

    printf("%d so nguyen to dau tien la:", x);

    for (int i = 2; dem < x; i++)
    {
        if (dk(i))
        {
            printf(" %d", i);
            dem++;
        }
    }
    return 0;
}