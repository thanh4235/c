#include <stdio.h>
int kq(int a, int b)
{
    int tong;
    if (b <= 12)
        tong = (b - a) * 6000;
    if (a <= 12 && b > 12)
        tong = (12 - a) * 6000 + (b - 12) * 7500;
    if (a > 12 && b > 12)
        tong = (b - a) * 7500;
    return tong;
}
int main()
{
    int a, b;
    printf("Nhap gio bat dau: ");
    scanf("%d", &a);
    printf("Nhap gio ket thuc: ");
    scanf("%d", &b);
    printf("Tong tien: %d", kq(a, b));
    return 0;
}