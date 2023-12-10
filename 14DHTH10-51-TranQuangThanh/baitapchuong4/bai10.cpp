#include <stdio.h>
void dk(int a)
{
    printf("\n%d tuan va %d ngay le", a / 7, a % 7);
}
int main()
{
    int a;
    do
    {
        printf("Nhap so ngay: ");
        scanf("%d", &a);
        if (a < 0)
            printf("Gia tri khong hop le!! Nhap lai\n");
    } while (a < 0);
    dk(a);
    return 0;
}