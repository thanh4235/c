// Lay max & min trong mang
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
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
    int max = mang[0], min = mang[0];
    for (int i = 0; i < a; i++)
    {
        if (max < mang[i])
            max = mang[i];
        if (min > mang[i])
            min = mang[i];
    }
    printf("Gia tri lon nhat trong mang la: %d\n", max);
    printf("Gia tri nho nhat trong mang la: %d\n", min);
    return 0;
}