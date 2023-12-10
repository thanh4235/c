#include <stdio.h>
void dk(int a)
{
    printf("20,000 VND: %d to\n", a / 20000);
    printf("10,000 VND: %d to\n", (a % 20000) / 10000);
    printf("5,000 VND: %d to\n", ((a % 20000) % 10000) / 5000);
    printf("con du %d VND\n", ((a % 20000) % 10000) % 5000);
}
int main()
{
    int a;
    do
    {
        printf("Nhap so tien: ");
        scanf("%d", &a);
        if (a <= 100000)
            printf("Vui long nhap so lon hon 100000\n");
    } while (a <= 100000);
    dk(a);
    return 0;
}