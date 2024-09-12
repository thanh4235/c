// Xuat ra n chu so chinh phuong
#include <stdio.h>
void so_chinh_phuong(int a)
{
    printf("%d so chinh phuong dau tien:", a);
    for (int i = 1; i <= a; i++)
    {
        printf(" %d", i * i);
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
    so_chinh_phuong(a);
    return 0;
}