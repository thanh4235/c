// 1+(1/2)+(1/3)+...+(1/n)
#include <stdio.h>
float tinh(float a)
{
    float tong = 0;
    for (int i = 1; i <= a; i++)
        tong = tong + (1 / (float)i);
    return tong;
}
int main()
{
    int a;
    do
    {
        printf("Nhap so nguen duong bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (a <= 0);
    printf("Tong: %f", tinh(a));
    return 0;
}