#include <stdio.h>
void input(int &a, int &b)
{
    printf("Nhap tu so: ");
    scanf("%d", &a);
    do
    {
        printf("Nhap mau so: ");
        scanf("%d", &b);
        if (b == 0)
            printf("Gia tri khong hop le!\n");
    } while (b == 0);
    printf("Phan so vua nhap: %d/%d\n", a, b);
}
void simplification(int tu, int mau)
{
    int x;
    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    };
    for (int i = 1; i <= tu || i <= mau; i++)
        if (tu % i == 0 && mau % i == 0)
            x = i;
    printf("Toi gian: %d/%d\n", tu / x, mau / x);
}
void calculation(int tu1, int mau1, int tu2, int mau2, int tu3, int mau3)
{
    int x, y;
    x = (tu1 * mau2 * mau3) + (tu2 * mau1 * mau3) + (tu3 * mau1 * mau2), y = mau1 * mau2 * mau3;
    printf("\nTong: %d/%d\n", x, y);
    simplification(x, y);
    x = tu1 * tu2 * tu3, y = mau1 * mau2 * mau3;
    printf("\nTich: %d/%d\n", x, y);
    simplification(x, y);
}
int main()
{
    int a, b, c, d, e, f;
    printf("\nNhap phan so thu nhat!\n");
    input(a, b);
    printf("\nNhap phan so thu hai\n");
    input(c, d);
    printf("\nNhap phan so thu ba\n");
    input(e, f);
    calculation(a, b, c, d, e, f);
    return 0;
}