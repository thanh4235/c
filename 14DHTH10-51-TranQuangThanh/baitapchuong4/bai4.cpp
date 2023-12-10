// so hoan thien
#include <stdio.h>
int dk(int a)
{
    int tong = 0;
    if (a <= 0)
        return false;
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
            tong += i;
    }
    if (tong == a)
        return true;
    return false;
}
int main()
{
    int a;
    printf("Nhap a: ");
    scanf("%d", &a);
    if (dk(a))
        printf("\n%d la so hoan thien", a);
    else
        printf("\n%d khong phai la so hoan thien", a);
    return 0;
}