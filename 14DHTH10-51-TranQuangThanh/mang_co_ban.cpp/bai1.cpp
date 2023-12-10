// Tính tổng các giá trị trong mảng
#include <stdio.h>
int main()
{
    int mang[] = {9, 8, 7, 6, 5, 4, 3}, tong = 0;
    int kichthuoc = sizeof(mang) / sizeof(mang[0]);
    for (int i = 0; i < kichthuoc; i++)
        tong = tong + mang[i];
    printf("Tong: %d", tong);
    return 0;
}