#include <stdio.h>
#include <conio.h>
float toan, van, anh, ly, su, hoa, dtb;
// Tính điểm tb
float diemtb()
{
    dtb = (toan + van + anh + ly + su + hoa) / 6;
    printf("Diem trung binh:%.2f\n", dtb);
    return dtb;
}
// Nhập dữ liệu
int nhap()
{
    printf("Nhap diem toan:");
    scanf("%f", &toan);
    if (toan < 0 or toan > 10)
    {
        printf("Diem khong the duoi 0 hoac tren 10\n");
        return nhap();
    }
    printf("Nhap diem van:");
    scanf("%f", &van);
    if (van < 0 or van > 10)
    {
        printf("Diem khong the duoi 0 hoac tren 10\n");
        return nhap();
    }
    printf("Nhap diem su:");
    scanf("%f", &su);
    if (su < 0 or su > 10)
    {
        printf("Diem khong the duoi 0 hoac tren 10\n");
        return nhap();
    }
    printf("Nhap diem ly:");
    scanf("%f", &ly);
    if (ly < 0 or ly > 10)
    {
        printf("Diem khong the duoi 0 hoac tren 10\n");
        return nhap();
    }
    printf("Nhap diem hoa:");
    scanf("%f", &hoa);
    if (hoa < 0 or hoa > 10)
    {
        printf("Diem khong the duoi 0 hoac tren 10\n");
        return nhap();
    }
    printf("Nhap diem anh:");
    scanf("%f", &anh);
    if (anh < 0 or anh > 10)
    {
        printf("Diem khong the duoi 0 hoac tren 10\n");
        return nhap();
    }
}

void main()
{
    nhap();
    diemtb();
    if (dtb >= 8)
    {
        printf("Xep Loai:Gioi");
    }
    else if (dtb >= 7)
    {
        printf("Xep Loai:Kha");
    }
    else if (dtb >= 5)
    {
        printf("Xep Loai:TB");
    }
    else
    {
        printf("Xep Loai:Yeu");
    }
}