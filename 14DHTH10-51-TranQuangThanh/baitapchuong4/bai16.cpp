#include <stdio.h>
int main()
{
    printf("Những số mà tổng và tích các số đó bằng nhau:");
    for (int x = 1; x <= 9; x++)
        for (int y = 1; y <= 9; y++)
            if ((x + y) == (x * y))
                printf(" %d%d", x, y);
    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++)
            for (int c = 1; c <= 9; c++)
                if ((a + b + c) == (a * b * c))
                    printf(" %d%d%d", a, b, c);
    return 0;
}