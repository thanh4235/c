// Kiem tra mot so nguyen x co phai la so hoan thien hay khong
#include <stdio.h>
bool kt(int a)
{
    int tong = 0;
    for (int i = 1; i < a; i++)
        if (a % i == 0)
            tong += i;
    if (tong == a)
        return true;
    return false;
}
int main()
{
    int x;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &x);
        if (x <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (x <= 0);
    if (kt(x))
        printf("%d la so hoan thien", x);
    else
        printf("%d khong phai la so hoan thien", x);
    return 0;
}