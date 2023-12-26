#include <stdio.h>
struct fraction
{
    int numerator;
    int denominator;
};
// Hàm nhập
void input(struct fraction *a)
{
    printf("\nNhap tu so: ");
    scanf("%d", &a->numerator);
    do
    {
        printf("Nhap mau so: ");
        scanf("%d", &a->denominator);
        if (a->denominator == 0)
            printf("Gia tri khong le!\n");
    } while (a->denominator == 0);
}
// Hàm so sánh phân số với 1
void compare_to_1(struct fraction a)
{
    printf("Phan so ");
    if (a.numerator / a.denominator < 1)
        printf("nho hon 1\n");
    else if (a.numerator / a.denominator > 1)
        printf("lon hon 1\n");
    else
        printf("bang 1\n");
}
// Hàm tìm ước chung lớn nhất
int common_divisor(struct fraction a)
{
    int b;
    for (int i = 1; i <= a.numerator || i <= a.denominator; i++)
        if (a.numerator % i == 0 && a.denominator % i == 0)
            b = i;
    return b;
}
// Hàm tối giản
void simplification(struct fraction a)
{
    int b = common_divisor(a);
    if (a.denominator < 0)
    {
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    printf("Toi gian: %d/%d\n", a.numerator / b, a.denominator / b);
}
// Hàm quy đồng 2 phân số
void common_denominator(struct fraction a, struct fraction b)
{
    printf("\nNhap 2 phan so de quy dong mau chung!\n");
    int a_divisor = common_divisor(a), b_divisor = common_divisor(b);
    printf("Sau khi quy dong 2 phan so:");
    printf(" %d/%d", (a.numerator / a_divisor) * (b.denominator / b_divisor), (a.denominator / a_divisor) * (b.denominator / b_divisor));
    printf(" %d/%d\n", (b.numerator / b_divisor) * (a.denominator / a_divisor), (b.denominator / b_divisor) * (a.denominator / a_divisor));
}
// Hàm tính tổng, hiệu, tích, thương
void calculation(struct fraction a, struct fraction b)
{
    struct fraction x;
    x.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator), x.denominator = a.denominator * b.denominator;
    printf("\nTong: %d/%d\n", x.numerator, x.denominator);
    simplification(x);
    x.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator), x.denominator = a.denominator * b.denominator;
    printf("\nHieu: %d/%d\n", x.numerator, x.denominator);
    simplification(x);
    x.numerator = a.numerator * b.numerator, x.denominator = a.denominator * b.denominator;
    printf("\nTich: %d/%d\n", x.numerator, x.denominator);
    simplification(x);
    x.numerator = a.numerator * b.denominator, x.denominator = a.denominator * b.numerator;
    printf("\nThuong: %d/%d\n", x.numerator, x.denominator);
    simplification(x);
}
void display(struct fraction a)
{
    printf("\nPhan so vua nhap: %d/%d\n", a.numerator, a.denominator);
    simplification(a);
}
int main()
{
    struct fraction a, b;
    printf("Nhap phan so bat ki!\n");
    input(&a);
    display(a);
    compare_to_1(a);
    printf("\nNhap 2 phan so de quy dong mau chung!\n");
    input(&a);
    input(&b);
    common_denominator(a, b);
    printf("\nNhap 2 phan so de tinh tong, hieu, tich, thuong!\n");
    input(&a);
    input(&b);
    calculation(a, b);
    return 0;
}