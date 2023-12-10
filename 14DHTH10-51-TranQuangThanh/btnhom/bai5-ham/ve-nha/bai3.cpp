// Tinh tong S(n)=1-2+3-4+...+n*(-1)^(n-1)
#include <stdio.h>
#include <math.h>
int tinh(int n)
{
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong = tong + (pow(-1, i - 1) * i);
    }
    return tong;
}
int main()
{
    int a;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf(" Vui long nhap so nguyen duong\n");
    } while (a <= 0);
    tinh(a);
    printf("Tong: %d", tinh(a));
    return 0;
}