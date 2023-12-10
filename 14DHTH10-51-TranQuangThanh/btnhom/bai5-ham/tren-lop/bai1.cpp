// Viet chuong trinh tinh dien tich hinh tam giac khi biet ba canh cua tam giac (yeu cau viet ham tinh dien tich tam giac)
#include <stdio.h>
#include <math.h>
float tamgiac(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    float s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}
int main()
{
    float a, b, c;
    do
    {
        printf("Nhap canh thu nhat: ");
        scanf("%f", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    do
    {
        printf("Nhap canh thu hai: ");
        scanf("%f", &b);
        if (b <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (b <= 0);
    do
    {
        printf("Nhap canh thu ba: ");
        scanf("%f", &c);
        if (c <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (c <= 0);
    printf("Dien tich tam giac la: %f", tamgiac(a, b, c));
    return 0;
}