// Nhap va xuat mang
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
void xuat(int mang[], int a)
{
    printf("Cac gia tri trong mang la:");
    for (int i = 0; i < a; i++)
        printf(" %d", mang[i]);
}
int main()
{
    int a, mang[a];
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    nhap(mang, a);
    xuat(mang, a);
    return 0;
}