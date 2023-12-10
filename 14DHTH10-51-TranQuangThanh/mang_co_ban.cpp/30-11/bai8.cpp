// Tìm kiếm các phần tử trong mảng
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &a);
    }
}
int main()
{
    int a;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &a);
    int mang[a];
    nhap(mang, a);
    int b;
    printf("Nhap gia tri ma ban muon tim vi tri cua no trong mang: ");
    scanf("%d", &b);
    for (int i = 0; i < a; i++)
    {
        if (mang[i] == b)
            printf("Tim thay %d nam o vi tri thu %d trong mang", b, i + 1);
        break;
    }
    printf("Khong the tim thay gia tri nao trong mang");
    return 0;
}