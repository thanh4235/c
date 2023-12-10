/* Hay khai bao mot cau truc mo ta hinh tron co cac thong tin: diem O lam tam va ban kinh r. Sau do viet chuong trinh thuc hien cac chuc nang sau:
- Nhap, xuat thong tin mot hinh tron
- Tính chu vi, dien tich hinh tron */
#include <stdio.h>
#include <math.h>

struct diem
{
    float x;
    float y;
};

struct hinhtron
{
    diem tam;
    float r;
};
float chuvi(float r)
{
    return r * 2 * M_PI;
}
float dientich(float r)
{
    return M_PI * pow(r, 2);
}
int main()
{
    hinhtron o;
    do
    {
        printf("Nhap ban kinh: ");
        scanf("%f", &o.r);
        if (o.r <= 0)
            printf("Gia tri khong hop le\n");
    } while (o.r <= 0);
    printf("\nChu vi hinh tron la %f", chuvi(o.r));
    printf("\nDien tich hinh tron la %f", dientich(o.r));
    return 0;
}