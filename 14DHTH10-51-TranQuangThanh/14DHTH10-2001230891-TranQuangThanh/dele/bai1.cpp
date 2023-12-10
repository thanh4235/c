#include <stdio.h>
#include <conio.h>

int dk(int n)
{
    do
    {
        if (n < 0 || n > 10)
        {
            printf("Dieu kien: so tu 0 den 10\n");
            printf("Nhap lai: ");
            scanf("%d", &n);
        }
    } while (n < 0 || n > 10);
    return n;
}
int main()
{
    int toan, van, hoa, anh;
    printf("Nhap diem toan: ");
    scanf("%d", &toan);
    toan = dk(toan);
    printf("Nhap diem van: ");
    scanf("%d", &van);
    van = dk(van);
    printf("Nhap diem hoa: ");
    scanf("%d", &hoa);
    hoa = dk(hoa);
    printf("Nhap diem anh: ");
    scanf("%d", &anh);
    anh = dk(anh);
    int min = toan;
    if (van < min)
        min = van;
    if (hoa < min)
        min = hoa;
    if (anh < min)
        min = anh;
    float dtb = ((toan + van) * 2 + hoa + anh) / 6;
    printf("Diem trung binh: %f\n", dtb);
    if (dtb >= 8.5 && min >= 6.5)
        printf("Loai gioi");
    else if (dtb < 8.5 && min > 5)
        printf("Loai kha");
    else if (dtb < 6.5 && min > 4)
        printf("Loai trung binh");
    else
        printf("Loai Yeu");
    getch();
    return 0;
}