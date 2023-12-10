// Tính tổng mảng và giá trị trung bình của mảng
#include <stdio.h>
void nhap(int mang[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
int main()
{
    int a, mang[a];
    do
    {
        printf("Nhap kich thuoc mang: ");
        scanf("%d", &a);
        if (a <= 0)
            printf("Vui long nhap so lon hon 0\n");
    } while (a <= 0);
    nhap(mang, a);
    int tong = 0, dem = 0;
    for (int i = 0; i < a; i++)
    {
        tong += mang[i];
        dem++;
    }
    printf("Tong mang: %d\nGia tri trung binh cua mang: %f", tong, (float)tong / dem);
    return 0;
}