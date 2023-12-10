#include <stdio.h>
int dk1(int a)
{
    while (a < 0)
    {
        printf("\nVui long nhap so lon hon 0!!\nNhap lai: ");
        scanf("%d", &a);
    }
    return a;
}
bool dk2(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int ucln(int a, int b)
{
    int c;
    for (int i = 1; i <= a || i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            c = i;
        }
    }
    return c;
}
int main()
{
    int n, m, dem = 0;
    printf("Nhap n: ");
    scanf("%d", &n);
    n = dk1(n);
    printf("Nhap m: ");
    scanf("%d", &m);
    m = dk1(m);
    for (int i = 2; dem < m; i++)
    {
        if (dk2(i) && ucln(i, n) == 1)
        {
            printf(" %d", i);
            dem++;
        }
    }
    return 0;
}