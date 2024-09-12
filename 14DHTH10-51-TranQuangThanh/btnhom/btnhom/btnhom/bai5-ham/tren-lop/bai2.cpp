/* Viet chuong trinh cho phep nguoi dung thuc hien mot trong cac yeu cau sau:
 1. Tinh tong cac uoc cua so nguyen n
 2. Tim so ngay cua mot thang khi biet thang va nam
 3. Doi cho 2 so nguyen x,y
 4. Tim BCNN cua hai so nguyen duong a va b
 5. Kiem tra so nguyen duong n co cac chu so toan la chu so le hay khong?
 (Yeu cau: Moi chuc nang viet ham thuc hien, ham main goi ham vua viet thuc thi)*/
#include <stdio.h>
void tong_cac_uoc()
{
    int a;
    do
    {
        printf("Nhap so nguyen bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    int tong = 0;
    for (int i = 1; i <= a; i++)
        if (a % i == 0)
            tong += i;
    printf("Tong cac uoc la %d", tong);
}
void tim_ngay()
{
    int thang, nam;
    do
    {
        printf("Nhap thang: ");
        scanf("%d", &thang);
        if (thang <= 0 || thang > 12)
            printf("Vui long nhap thang tu 1 den 12\n");
    } while (thang <= 0 || thang > 12);
    do
    {
        printf("Nhap nam: ");
        scanf("%d", &nam);
        if (nam <= 0)
            printf("Vui long nhap nam lon hon 0\n");
    } while (nam <= 0);
    switch (thang)
    {
    case 2:
        if (nam % 4 == 0 && nam % 100 != 0)
            printf("Thang %d nam %d co 29 ngay\n", thang, nam);
        else
            printf("Thang %d nam %d co 28 ngay\n", thang, nam);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Thang %d nam %d co 30 ngay\n", thang, nam);
        break;
    default:
        printf("Thang %d nam %d co 31 ngay\n", thang, nam);
    }
}
void doi_cho()
{
    int x, y;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);
    printf("Nhap so nguyen y: ");
    scanf("%d", &y);
    int a = x, b = y;
    y = a;
    x = b;
    printf("\nx = %d", x);
    printf("\ny = %d", y);
}
void bcnn()
{
    int a, b;
    do
    {
        printf("Nhap so nguyen thu nhat: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen duong\n");
    } while (a <= 0);
    do
    {
        printf("Nhap so nguyen thu hai: ");
        scanf("%d", &b);
        if (b <= 0)
            printf("Vui long nhap so nguyen duong\n");
    } while (b <= 0);
    int ucln;
    for (int i = 1; i <= a || i <= b; i++)
        if (a % i == 0 && b % i == 0)
            ucln = i;
    float bcnn = (float)(a * b) / ucln;
    printf("Boi chung nho nhat cua %d va %d la %f", a, b, bcnn);
}
int kiem_tra()
{
    int a;
    do
    {
        printf("Nhap so nguyen duong bat ki: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so nguyen duong\n");
    } while (a <= 0);
    printf("%d co cac chu so toan la chu so le hay khong?", a);
    while (a / 10 != 0)
    {
        if ((a % 10) % 2 == 0)
        {
            printf(" Khong phai");
            return 0;
        }
        a = a / 10;
    }
    printf(" Phai");
    return 0;
}
int main()
{
    int a;
    printf("Hay chon so tu 1 den 5 de thuc hien mot trong cac yeu cau sau:\n");
    printf("(1) Tinh tong cac uoc cua so nguyen n\n");
    printf("(2) Tim so ngay cua mot thang khi biet thang va nam\n");
    printf("(3) Doi cho 2 so nguyen x,y\n");
    printf("(4) Tim BCNN cua hai so nguyen duong a va b\n");
    printf("(5) Kiem tra so nguyen duong n co cac chu so toan la chu so le hay khong?\n");
    do
    {
        printf("Chon yeu cau: ");
        scanf("%d", &a);
        if (a < 1 || a > 5)
            printf("Vui long chon so tu 1 den 5\n");
    } while (a < 1 || a > 5);
    switch (a)
    {
    case 1:
        tong_cac_uoc();
        break;
    case 2:
        tim_ngay();
        break;
    case 3:
        doi_cho();
        break;
    case 4:
        bcnn();
        break;
    case 5:
        kiem_tra();
        break;
    default:
        printf("???");
    }
    return 0;
}
