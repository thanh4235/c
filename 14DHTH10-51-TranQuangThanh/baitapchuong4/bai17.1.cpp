#include <stdio.h>
bool dk(long b)
{
    while (b != 0)
    {
        long x = b % 10;
        b = b / 10;
        long z = b;

        while (z != 0)
        {
            long y = b % 10;
            if (x == y)
                return false;
            z = z / 10;
        }
    }
    return true;
}

int main()
{
    long a;
    printf("Nhap so bat ki: ");
    scanf("%d", &a);
    // đếm số đầu
    long b = a;
    while (b >= 10)
    {
        b = b / 10;
    }
    printf("Chu so hang dau tien: %ld\n", b);

    // Tổng các chữ số
    b = a;
    long dem = 0;
    while (b != 0)
    {
        dem = dem + (b % 10);
        b = b / 10;
    }
    printf("Tong cac chu so: %ld\n", dem);

    // Chữ số lớn nhất
    b = a;
    long max = b % 10;

    while (b != 0)
    {
        b = b / 10;
        if (max < (b % 10))
            max = b % 10;
    }
    printf("Chu so lon nhat: %ld\n", max);

    // Số chữ số của N
    b = a;
    dem = 0;
    while (b != 0)
    {
        b = b / 10;
        dem++;
    }
    printf("So chu so cua N: %ld\n", dem);

    // Các chữ số có khác nhau đôi một không
    b = a;
    printf("Cac chu so co khac nhau doi mot khong?");
    if (dk(b))
        printf(" Co");
    else
        printf(" Khong");

    return 0;
}