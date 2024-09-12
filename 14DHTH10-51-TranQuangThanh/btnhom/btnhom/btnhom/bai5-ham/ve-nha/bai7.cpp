// Xuat n chu so nguyen to dau tien
#include <stdio.h>
bool kt(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return false;
    return true;
}
void so_nguyen_to(int a)
{
    int dem = 0;
    printf("%d so nguyen to dau tien la:", a);
    for (int i = 2; dem < a; i++)
        if (kt(i))
        {
            printf(" %d", i);
            dem++;
        }
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
    so_nguyen_to(a);
    return 0;
}