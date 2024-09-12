// S(n)=1+(1/3)+(1/5)+...+1/(2n+1)
#include <stdio.h>
float tinh(float n)
{
    float tong = 0;
    for (int i = 0; i <= n; i++)
        tong = tong + (1 / ((float)(2 * i) + 1));
    return tong;
}
int main()
{
    int a;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &a);
        if (a < 0)
            printf("Vui long nhap so lon hon hoac bang 0");
    } while (a < 0);
    printf("Tong: %f", tinh(a));
    return 0;
}