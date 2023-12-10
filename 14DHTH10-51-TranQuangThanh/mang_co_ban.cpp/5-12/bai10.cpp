// Viet ham tinh tong cac gia tri le trong mang 1 chieu cac so nguyen
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
int tinh(int mang[], int a)
{
    int tong = 0;
    for (int i = 0; i < a; i++)
        if (mang[i] % 2 != 0)
            tong += mang[i];
    return tong;
}
int main()
{
    int mang[100], a;
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (a <= 0);
    nhap(mang, a);
    printf("Tong: %d", tinh(mang, a));
    return 0;
}