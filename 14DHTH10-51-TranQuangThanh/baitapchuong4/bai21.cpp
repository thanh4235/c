#include <stdio.h>
void kt(int a, int b, int c)
{
    if (b < 10 && c < 10)
        printf("%d:0%d:0%d\n", a, b, c);
    if (b < 10 && c > 10)
        printf("%d:0%d:%d\n", a, b, c);
    if (b > 10 && c < 10)
        printf("%d:%d:0%d\n", a, b, c);
    if (b > 10 && c > 10)
        printf("%d:%d:%d\n", a, b, c);
}
void truoc(int a, int b, int c)
{
    if (c == 0)
    {
        c = 59;
        if (b == 0)
        {
            b = 59;
            a--;
        }
        else
            b--;
    }
    else
        c--;

    printf("truoc mot giay: ");
    kt(a, b, c);
}
void sau(int a, int b, int c)
{
    if (c == 59)
    {
        c = 0;
        if (b == 59)
        {
            b = 0;
            a++;
        }
        else
            b++;
    }
    else
        c++;

    printf("sau mot giay: ");
    kt(a, b, c);
}
int main()
{
    int a, b, c;
    do
    {
        printf("Nhap so gio: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0!\n");
    } while (a <= 0);
    do
    {
        printf("Nhap so phut: ");
        scanf("%d", &b);
        if (b < 0)
            printf("Vui long nhap so lon hon hoac bang 0\n");
    } while (b < 0);
    do
    {
        printf("Nhap so giay: ");
        scanf("%d", &c);
        if (c < 0)
            printf("Vui long nhap so lon hon hoac bang 0\n");
    } while (c < 0);
    printf("\nThoi gian ban vua nhap: ");
    kt(a, b, c);
    truoc(a, b, c);
    sau(a, b, c);
    return 0;
}