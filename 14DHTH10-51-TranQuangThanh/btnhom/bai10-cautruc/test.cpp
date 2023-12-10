#include <stdio.h>
struct hinhchunhat
{
    int dai;
    int rong;
};
void nhap(hinhchunhat &a)
{
    printf("Nhap chieu dai: ");
    scanf("%d", &a.dai);
    printf("Nhap chieu rong: ");
    scanf("%d", &a.rong);
}
void xuat(hinhchunhat a)
{
    printf("Chieu dai la: %d\n", a.dai);
    printf("Chieu rong la: %d\n", a.rong);
}
void tinh(hinhchunhat a)
{
    printf("chu vi la: %d\n", (a.dai + a.rong) * 2);
    printf("Dien tich la: %d", a.dai * a.rong);
}
int main()
{
    hinhchunhat x;
    nhap(x);
    xuat(x);
    tinh(x);
    return 0;
}