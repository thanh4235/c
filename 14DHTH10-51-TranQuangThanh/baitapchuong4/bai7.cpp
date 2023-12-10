// dem so uoc cua so nguyen n
#include <stdio.h>
void dk(int a)
{
    int dem = 0;
    printf("Cac so uoc cua %d la:", a);
    for (int i = 1; i <= a; i++)
        if (a % i == 0)
        {
            printf(" %d", i);
            dem++;
        }
    printf("\nCo tat ca %d uoc so", dem);
}
int main()
{
    int a;
    do
    {
        printf("Nhap so bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0");
    } while (a <= 0);
    dk(a);
    return 0;
}
