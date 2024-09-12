// S(n)=(1/2)+(1/4)+...(1/2n)
#include <stdio.h>
float tinh(float n)
{
    float tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong = tong + (1 / ((float)2 * i));
    }
    return tong;
}
int main()
{
    int a;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen duong\n");
    } while (a <= 0);
    printf("Tong: %f", tinh(a));
    return 0;
}