#include <stdio.h>
void dk(int a)
{
    int tong = 0, b;
    for (int i = 1; tong + i + 1 < a; i++)
    {
        b = i;
        tong += i;
    }
    printf("\nn=%d", b);
}
int main()
{
    int a;
    do
    {
        printf("Nhap so lon hon 0: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    dk(a);
    return 0;
}