// Vieet chuong trinh dao so nguyen n
#include <stdio.h>
void dao_so(int n)
{
    printf("Dao so cua %d la ", n);
    while (n / 10 != 0)
    {
        printf("%d", n % 10);
        n = n / 10;
    }
    printf("%d", n % 10);
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
    dao_so(a);
    return 0;
}
