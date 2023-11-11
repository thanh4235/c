#include <stdio.h>
int main()
{
    int n, m, i, a = 0;
    printf("Nhập n: ");
    scanf("%d", &n);
    do
    {
        printf("Nhập m: ");
        scanf("%d", &m);
        if (m < n)
            printf("Vui lòng nhập lại!!\n");
    } while (m < n);
    for (i = n; i <= m; i++)
        if (i % 2 == 0)
            a++;

    printf("có %d số chẵn trong khoảng (%d,%d)", a, n, m);
    return 0;
}