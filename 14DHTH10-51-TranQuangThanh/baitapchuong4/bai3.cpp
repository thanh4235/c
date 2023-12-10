#include <stdio.h>
int dk(int a)
{
    if (a <= 0)
        return false;
    for (int i = 1; i <= a; i++)
        if (a / i == i)
            return true;
    return false;
}
int main()
{
    int a;
    printf("Nhap mot so bat ki: ");
    scanf("%d", &a);
    if (dk(a))
        printf("%d la so chinh phuong", a);
    else
        printf("%d khong phai la so chinh phuong", a);
    return 0;
}