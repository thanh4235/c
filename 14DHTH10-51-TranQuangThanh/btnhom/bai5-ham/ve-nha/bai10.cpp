#include <stdio.h>
bool check(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return false;
    return true;
}
int divisor(int a, int b)
{
    int x;
    for (int i = 1; i <= a || i <= b; i++)
        if (a % i == 0 && b % i == 0)
            x = i;
    return x;
}
void research(int a, int b)
{
    int count = 0;
    printf("\n%d so nguyen to cung nhau voi so %d la:", b, a);
    for (int i = 2; count < b; i++)
        if (check(i) && divisor(a, i) == 1)
        {
            printf(" %d", i);
            count++;
        }
}
int main()
{
    int a, b;
    do
    {
        printf("Nhap so bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Gia tri khong hop le\n");
    } while (a <= 0);
    do
    {
        printf("Ban muon bao nhieu so nguyen to cung nhau voi so %d: ", a);
        scanf("%d", &b);
        if (b <= 0)
            printf("Gia tri khong hop le\n");
    } while (b <= 0);
    research(a, b);
    return 0;
}