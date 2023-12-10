// Tinh tong cac so nguyen to nho hon n
#include <stdio.h>
bool kt(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return false;
    return true;
}
int tinh(int n)
{
    int tong = 0;
    for (int i = 1; i < n; i++)
        if (kt(i))
            tong += i;
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
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (a <= 0);
    printf("Tong: %d", tinh(a));
    return 0;
}