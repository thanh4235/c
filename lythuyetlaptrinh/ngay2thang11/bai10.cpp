#include <stdio.h>
#include <conio.h>
int main()
{
    int i, tong = 0;
    for (i = 1; i <= 100; i++)
        tong = tong + i;
    printf("Tổng các số tự nhiên lớn nhất nhỏ hơn 100 là %d", tong);
    getch();
}