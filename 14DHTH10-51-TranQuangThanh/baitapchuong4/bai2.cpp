// kiem tra so nguyen to
#include <stdio.h>
int dk(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a;

    printf("Nhap a: ");
    scanf("%d", &a);

    dk(a);
    if (dk(a))
        printf("\n%d la so nguyen to", a);
    else
        printf("\n%d khong phai la so nguyen to", a);
    return 0;
}
