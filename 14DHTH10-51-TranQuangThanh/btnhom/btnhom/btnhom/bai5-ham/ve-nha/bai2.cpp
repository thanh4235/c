// Nhap so nguyen duong h, viet chuong trinh in ra man hinh mot trong cac tam giac sau (nguoi dung tuy chon)
#include <stdio.h>
void tamgiac_vuong1(int a)
{
    int x = a, y = a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = x - 1; j < y; j++)
        {
            printf("*");
        }
        if (x > 0)
        {
            x--;
        }
        printf("\n");
    }
}
void tamgiac_can(int a)
{
    int x = a;
    int y = a;
    int z = a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            printf(" ");
        }
        x--;
        for (int k = z * 2 - 2; k < y * 2 - 1; k++)
        {
            printf("*");
        }
        z--;
        printf("\n");
    }
}
void tamgiac_vuong2(int a)
{
    int x = a, y = 1;
    for (int i = 1; i <= a; i++)
    {

        for (int j = x + 1; j <= a; j++)
        {
            printf(" ");
        }
        x--;
        for (int k = y; k <= a; k++)
        {
            printf("*");
        }
        y++;
        printf("\n");
    }
}

int main()
{
    int a, b;
    printf("    * * * * * * * * * * * * * *\n");
    printf("    *  *          *    *****  *\n");
    printf("    *  **        ***    ****  *\n");
    printf("    *  ***      *****    ***  *\n");
    printf("    *  ****    *******    **  *\n");
    printf("    *  *****  *********    *  *\n");
    printf("    *   (1)      (2)     (3)  *\n");
    printf("    * * * * * * * * * * * * * *\n");
    do
    {
        printf("Chon mot hinh tu 1 den 3 de in: ");
        scanf("%d", &a);
        if (a <= 0 || a > 3)
            printf("Vui long chon so tu 1 den 3\n");
    } while (a <= 0 || a > 3);
    do
    {
        printf("Nhap chieu cao tam giac: ");
        scanf("%d", &b);
        if (b <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (b <= 0);
    switch (a)
    {
    case 1:
        tamgiac_vuong1(b);
        break;
    case 2:
        tamgiac_can(b);
        break;
    case 3:
        tamgiac_vuong2(b);
        break;
    default:
        printf("???\n");
    }
    return 0;
}