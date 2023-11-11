#include <stdio.h>
int main()
{
    int a, b, c, d, i;
    printf("Nhập số thứ nhất: ");
    scanf("%d", &a);
    printf("Nhập số thứ hai: ");
    scanf("%d", &b);

    for (i = 1; i <= b || i <= a; i++)
        if (a % i == 0 && b % i == 0)
            c = i;

    // công thức tính BSCNN dựa vào USCLN: (a*b)/USCLN
    d = (a * b) / c;

    printf("Ước số chung lớn nhất của 2 số: %d\n", c);
    printf("Bội số chung nhỏ nhất của 2 số: %d", d);
}