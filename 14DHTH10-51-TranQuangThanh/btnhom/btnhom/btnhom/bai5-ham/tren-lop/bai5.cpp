// Tinh can trong can
#include <stdio.h>
#include <math.h>
float tinh(float a)
{
    float tong = 0;
    for (int i = 1; i <= a; i++)
        tong = sqrt(tong + 2);
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
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (a <= 0);
    printf("Tong: %f", tinh(a));
    return 0;
}