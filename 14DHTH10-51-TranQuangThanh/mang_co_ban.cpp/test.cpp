// nhập mảng a với n số nguyên tố
#include <stdio.h>
int main()
{
    int x, y, z;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &x);
    int a[x - 1];
    int dem = 1;
    for (int i = 0; i < x; i++)
    {

        printf("Nhap so thu %d: ", dem++);
        scanf("%d", &a[i]);
    }
    int kichthuoc = sizeof(a) / sizeof(a[0]);
    printf("Mang vua nhap:");
    for (int i = 0; i <= kichthuoc; i++)
        printf(" %d", a[i]);
    return 0;
}