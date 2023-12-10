#include <stdio.h>
void dk(int x)
{
    if (x % 2 == 0)
        printf("Chan");
    else
        printf("Le");
}
int main()
{
    int x;
    do
    {
        printf("Nhap x: ");
        scanf("%d", &x);
        if (x <= 0)
            printf("Du lieu khong hop le!! Nhap lai\n");
    } while (x <= 0);
    dk(x);
}