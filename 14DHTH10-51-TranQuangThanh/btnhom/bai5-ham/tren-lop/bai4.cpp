// Dem so chinh phuong nho hon n
#include <stdio.h>
bool kt(int a)
{
    for (int i = 1; i <= a; i++)
    {
        if (i * i == a)
            return true;
    }
    return false;
}
int dem_so(int n)
{
    int dem = 0;
    for (int i = 1; i < n; i++)
    {
        if (kt(i))
        {
            printf("\n%d", i);
            dem++;
        }
    }
    return dem;
}
int main()
{
    int n;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &n);
        if (n <= 0)
            printf("Vui long nhap so nguyen lon hon 0\n");
    } while (n <= 0);
    printf("\nCo %d so chinh phuong", dem_so(n));
    return 0;
}

struct Position
{
    int x;
    int y;
};

struct Rectangle
{
    int width;
    int height;
    Position position;
};
