#include <stdio.h>
int main()
{
    float a, b, c, d;
    printf("Nhap don gia: ");
    scanf("%f", &a);
    printf("Nhap so luong: ");
    scanf("%f", &b);
    c = a * b;
    d = (float)a * b * (1 - 0.03);
    if (c > 100)
    {
        printf("Thanh tien: %.2f", d);
        return 0;
    }
    else
    {
        printf("Thanh tien: %.2f", c);
        return 0;
    }
}