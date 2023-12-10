// Viet ham liet ke cac gia tri trong mang 1 chieu cac so thuc thuoc doan [x,y] cho truoc
#include <stdio.h>
void nhap(float mang[], float a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%f", &mang[i]);
    }
}
void kq(float x, float y, float mang[], float a)
{
    printf("Cac gia tri thuoc doan [%.2f,%.2f] la", x, y);
    for (int i = 0; i < a; i++)
    {
        if (mang[i] >= x && mang[i] <= y)
            printf(" %.2f", mang[i]);
    }
}
int main()
{
    int a;
    float x, y, mang[100];
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    nhap(mang, a);
    printf("\nNhap khoang gioi han [min,max]\n");
    do
    {
        printf("min=");
        scanf("%f", &x);
        printf("max=");
        scanf("%f", &y);
        if (x > y)
            printf("Gia tri khong hop le!! Vui long nhap lai\n");
    } while (x > y);
    kq(x, y, mang, a);
    return 0;
}