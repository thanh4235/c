// Tính trung bình các số chẵn trong mảng
#include <stdio.h>
int main()
{
    int mang[] = {5, 64, 86, 42, 315, 1};
    int kichthuoc = sizeof(mang) / sizeof(mang[0]);
    int dem = 0, tong = 0;
    for (int i = 0; i <= kichthuoc; i++)
        if (mang[i] % 2 == 0)
        {
            dem++;
            tong += mang[i];
        }
    float kq = (float)tong / dem;
    printf("\nTrung binh cac so chan trong mang: %f", kq);
    return 0;
}