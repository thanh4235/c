// Liet ke cac gia tri chan
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
void tim(int mang[], int a)
{
    printf("Cac gia tri chan trong mang la:");
    for (int i = 0; i < a; i++)
    {
        if (mang[i] % 2 == 0)
            printf(" %d", mang[i]);
    }
}
int main()
{
    int a, mang[100];
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (a <= 0);
    nhap(mang, a);
    tim(mang, a);
    return 0;
}