/* Hay khai bao mot cau truc mo ta phan so co cac thong tin tu so va mau so. Sau do viet chuong trinh thuc hien cac chuc nang sau:
- Nhap va xuat phan so
- Kiem tra phan so mau co phai khac 0
- Tinh cong/tru/nhan/chia 2 phan so
- Toi gian phan so */
#include <stdio.h>
struct phanso
{
    int tu;
    int mau;
};
void toi_gian(int tu, int mau)
{
    int ucln;
    for (int i = 1; i <= tu || i <= mau; i++)
        if (tu % i == 0 && mau % i == 0)
            ucln = i;
    printf("\nSau khi toi gian: %d/%d\n", tu / ucln, mau / ucln);
}
void tinh(int tu1, int mau1, int tu2, int mau2)
{
    printf("\nTong 2 phan so: %d/%d", (tu1 * mau2) + (tu2 * mau1), mau1 * mau2);
    toi_gian((tu1 * mau2) + (tu2 * mau1), mau1 * mau2);
    printf("\nHieu 2 phan so: %d/%d", (tu1 * mau2) - (tu2 * mau1), mau1 * mau2);
    toi_gian((tu1 * mau2) - (tu2 * mau1), mau1 * mau2);
    printf("\nTich 2 phan so: %d/%d", tu1 * tu2, mau1 * mau2);
    toi_gian(tu1 * tu2, mau1 * mau2);
    printf("\nThuong 2 phan so: %d/%d", tu1 * mau2, mau1 * tu2);
    toi_gian(tu1 * mau2, mau1 * tu2);
}
int main()
{
    phanso a, b;
    printf("Nhap tu so cua phan so thu nhat: ");
    scanf("%d", &a.tu);
    do
    {
        printf("Nhap mau so cua phan so thu nhat: ");
        scanf("%d", &a.mau);
        if (a.mau == 0)
            printf("Mau phai khac 0! Vui long nhap lai!!\n");
    } while (a.mau == 0);
    printf("Phan so vua nhap la: %d/%d", a.tu, a.mau);
    toi_gian(a.tu, a.mau);
    printf("Nhap tu so cua phan so thu hai: ");
    scanf("%d", &b.tu);
    do
    {
        printf("Nhap mau so cua phan so thu hai: ");
        scanf("%d", &b.mau);
        if (b.mau == 0)
            printf("Mau phai khac 0! Vui long nhap lai!!\n");
    } while (b.mau == 0);
    printf("Phan so vua nhap la: %d/%d", b.tu, b.mau);
    toi_gian(b.tu, b.mau);
    tinh(a.tu, a.mau, b.tu, b.mau);
    return 0;
}