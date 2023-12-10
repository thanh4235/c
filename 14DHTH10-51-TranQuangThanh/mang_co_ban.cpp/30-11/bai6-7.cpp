// Đảo mảng và kiểm tra tính đối xứng của mảng
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
void dao_mang(int mang[], int a, int mang2[], int b)
{
    for (int i = 0; i < a; i++)
    {
        b--;
        mang2[b] = mang[i];
    }
    printf("\nMang ban dau:");
    for (int i = 0; i < a; i++)
        printf(" %d", mang[i]);
    printf("\nDao mang:");
    for (int i = 0; i < a; i++)
        printf(" %d", mang2[i]);
}
bool kt(int mang[], int a, int mang2[], int b)
{
    for (int i = 0; i < a; i++)
        if (mang2[i] != mang[i])
            return false;
    return true;
}
int main()
{
    int a;
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    int mang[a];
    nhap(mang, a);
    int b = a, mang2[b];
    dao_mang(mang, a, mang2, b);
    printf("\nCac gia tri trong mang co doi xung voi nhau hay khong?");
    if (kt(mang, a, mang2, b))
        printf(" Co");
    else
        printf(" Khong");
    return 0;
}