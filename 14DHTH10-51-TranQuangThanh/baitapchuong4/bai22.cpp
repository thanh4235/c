#include <stdio.h>
bool kq(int a)
{
    int mot = a % 10;
    int hai = (a / 10) % 10;
    int bon = (a / 1000) % 10;
    int nam = (a / 10000) % 10;
    if (mot == nam && hai == bon)
        return true;
    return false;
}
int main()
{
    int a;
    do
    {
        printf("Nhap a: ");
        scanf("%d", &a);
        if (a < 10000 || a > 100000)
            printf("Vui long nhap so nguyen duong gom 5 chu so\n");
    } while (a < 10000 || a > 100000);
    if (kq(a))
        printf("%d la so doi xung", a);
    else
        printf("%d la so khong doi xung", a);
    return 0;
}