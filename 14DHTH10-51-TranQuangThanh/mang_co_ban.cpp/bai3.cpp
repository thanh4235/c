// Đảo ngược các phần tử trong mảng
#include <stdio.h>
int main()
{
    int mang[] = {5, 48, 64, 1, 78, 84, 156, 2};
    int kichthuoc = sizeof(mang) / sizeof(mang[0]);
    printf("luc dau:");
    for (int i = 0; i < kichthuoc; i++)
        printf(" %d", mang[i]);
    printf("\nluc sau:");
    while (kichthuoc > 0)
    {
        kichthuoc--;
        printf(" %d", mang[kichthuoc]);
    }
    return 0;
}