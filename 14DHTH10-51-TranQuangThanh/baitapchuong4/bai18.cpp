#include <stdio.h>
bool nam_nhuan(int a)
{
    if (a % 4 == 0 && a % 100 != 0)
        return true;
    return false;
}
int kt(int thang, int nam)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (nam_nhuan(nam))
            return 29;
        else
            return 28;
    default:
        printf("Loi\n");
        return 0;
    }
}
void truoc(int ngay, int thang, int nam)
{
    printf("truoc do 1 ngay: ");
    if (ngay == 1 && thang != 1)
        printf("%d/%d/%d\n", kt(thang - 1, nam), thang - 1, nam);
    else if (ngay == 1 && thang == 1)
        printf("31/12/%d\n", nam - 1);
    else
        printf("%d/%d/%d\n", ngay - 1, thang, nam);
}
void sau(int ngay, int thang, int nam)
{
    printf("sau do 1 ngay: ");
    if (ngay == kt(thang, nam) && thang != 12)
        printf("1/%d/%d\n", thang + 1, nam);
    else if (ngay == kt(thang, nam) && thang == 12)
        printf("1/1/%d\n", nam + 1);
    else
        printf("%d/%d/%d\n", ngay + 1, thang, nam);
}
int main()
{
    int ngay, thang, nam;
    do
    {
        printf("Nhap nam: ");
        scanf("%d", &nam);
        if (nam <= 0)
            printf("Khong hop le \n");
    } while (nam <= 0);
    do
    {
        printf("Nhap thang: ");
        scanf("%d", &thang);
        if (thang <= 0 || thang > 12)
            printf("Khong hop le\n");
    } while (thang <= 0 || thang > 12);
    do
    {
        printf("Nhap ngay: ");
        scanf("%d", &ngay);
        if (ngay <= 0 || ngay > kt(thang, nam))
            printf("Khong hop le\n");
    } while (ngay <= 0 || ngay > kt(thang, nam));
    printf("Ngay,thang,nam ma ban vua nhap: %d/%d/%d\n", ngay, thang, nam);
    truoc(ngay, thang, nam);
    sau(ngay, thang, nam);
    return 0;
}