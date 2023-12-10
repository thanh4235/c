#include <stdio.h>
int ucln(int a, int b)
{
    int c;
    for (int i = 1; i <= a || i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            c = i;
        }
    }
    return c;
}
int main()
{
    int a, b;
    printf("Nhap a,b: ");
    scanf("%d", &a);
    printf("hàng trăm: %d", a / 100);
    printf("hàng chục: %d", a / 10);
    printf("hàng đơn vị: %d", a / 100);

    return 0;
}