#include <stdio.h>
#include <conio.h>
int main()
{
    for (int i = 10; i <= 90; i++)
        printf("%d,%d\n", i, 100 - i);
    getch();
    return 0;
}