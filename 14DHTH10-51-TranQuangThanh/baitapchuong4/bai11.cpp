#include <stdio.h>
void dk(int a)
{
    printf("%dh:%dm:%ds", (a / 60) / 60, (a / 60) % 60, a - ((a / 3600) * 3600) - (((a / 60) % 60) * 60));
}
int main()
{
    int a;
    do
    {
        printf("Nhap so giay: ");
        scanf("%d", &a);
        if (a < 0)
            printf("Gia tri khong hop le!! Nhap lai\n");
    } while (a < 0);
    dk(a);
    return 0;
}