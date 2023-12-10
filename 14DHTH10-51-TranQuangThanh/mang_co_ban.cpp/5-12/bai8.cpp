// Viet ham liet ke cac gia tri am trong mang 1 chieu cac so nguyen
#include <stdio.h>

void nhap(float mang[], float a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%f", &mang[i]);
    }
}
void tim_so_am(float mang[], float a)
{
    printf("Cac gia tri am trong mang la:");
    for (int i = 0; i < a; i++)
        if (mang[i] < 0)
            printf(" %.2f", mang[i]);
}
int main()
{
    int a;
    float mang[100];
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    nhap(mang, a);
    tim_so_am(mang, a);
    return 0;
}