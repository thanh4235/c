// Viet ham tim doan [a,b] sao cho doan nay chua tat ca cac gia tri cua mang 1 chieu cac so nguyen
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
    int max = mang[0], min = mang[0];
    for (int i = 0; i < a; i++)
    {
        if (min > mang[i])
            min = mang[i];
        if (max < mang[i])
            max = mang[i];
    }
    printf("Mang thuoc doan [%d,%d]", min, max);
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