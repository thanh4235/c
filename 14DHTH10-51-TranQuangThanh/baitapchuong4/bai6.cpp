#include <stdio.h>
int dk(int a)
{
    if (a <= 0)
        return false;
    for (int i = 1; i <= a; i++)
    {
        if (i * i == a)
            return true;
    }
    return false;
}
int main()
{
    int a, dem = 0;
    do
    {
        printf("Nhap so bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0");
    } while (a <= 0);
    printf("%d so chinh phuong dau tien", a);
    for (int i = 1; dem < a; i++)
    {
        if (dk(i))
        {
            printf(" %d", i);
            dem++;
        }
    }
    return 0;
}