// Tim vi tri cac gia tri am trong mang
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
    for (int i = 0; i < a; i++)
        if (mang[i] < 0)
            printf("%d nam o vi tri thu %d trong mang\n", mang[i], i + 1);
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
    tim(mang, a);
    return 0;
}