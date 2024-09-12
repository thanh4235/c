// Tinh n!=1*2*3*...*n
#include <stdio.h>
int tinh(int a)
{
    int tich = 1;
    for (int i = 1; i <= a; i++)
        tich = tich * i;
    return tich;
}
int main()
{
    int a;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (a <= 0);
    printf("n!=%d", tinh(a));
    return 0;
}