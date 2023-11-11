#include <stdio.h>
#include <conio.h>
#include <math.h>
int dk(int n)
{
    do
    {
        if (n <= 0)
        {
            printf("Vui long nhap so nguyen duong\n");
            printf("Nhap lai: ");
            scanf("%d", &n);
        }
    } while (n <= 0);
    return n;
}
int main()
{
    int m, n, p, q;
    printf("Nhap m: ");
    scanf("%d", &m);
    m = dk(m);
    printf("Nhap n: ");
    scanf("%d", &n);
    n = dk(n);
    printf("Nhap p: ");
    scanf("%d", &p);
    p = dk(p);
    printf("Nhap q: ");
    scanf("%d", &q);
    q = dk(q);
    float kq = pow(m, n) + pow(n, p) + pow(q, m);
    printf("m^n + n^p + q^m = %f", kq);
    getch();
    return 0;
}