#include <stdio.h>
int main()
{
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 0; d <= 9; d++)
                    for (int e = 0; e <= 9; e++)
                    {
                        if (a == b && a != c && a != d && a != e)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (a == c && a != b && a != d && a != e)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (a == d && a != c && a != b && a != e)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (a == e && a != c && a != d && a != b)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (b == c && b != a && b != d && b != e)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (b == d && b != a && b != c && b != e)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (b == e && b != a && b != d && b != c)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (c == d && c != a && c != b && c != e)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                        if (c == e && c != a && c != b && c != d)
                            printf(" %d%d%d%d%d", a, b, c, d, e);
                    }
    return 0;
}