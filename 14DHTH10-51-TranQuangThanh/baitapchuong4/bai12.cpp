#include <stdio.h>
float dk(float a)
{
    do
    {
        if (a == 0)
        {
            printf("Dieu kien: Mau phai khac 0\n");
            printf("Nhap lai: ");
            scanf("%f", &a);
        }
    } while (a == 0);
    return a;
}
int main()
{
    float a, b, c, d, e, f;
    printf("Co 3 phan so: a/b c/d e/f\nNhap a: ");
    scanf("%f", &a);
    printf("Nhap b: ");
    scanf("%f", &b);
    dk(b);
    printf("Nhap c: ");
    scanf("%f", &c);
    printf("Nhap d: ");
    scanf("%f", &d);
    dk(d);
    printf("Nhap e: ");
    scanf("%f", &e);
    printf("Nhap f: ");
    scanf("%f", &f);
    dk(f);
    float tong = (a / b) + (c / d) + (e / f);
    float tich = (a / b) * (c / d) * (e / f);
    printf("\n%f %f", tong, tich);
    printf("\ntong cua 3 phan so la: %.2f", (a / b) + (c / d) + (e / f));
    printf("\ntich cua 3 phan so la: %.2f", (a / b) * (c / d) * (e / f));
    return 0;
}