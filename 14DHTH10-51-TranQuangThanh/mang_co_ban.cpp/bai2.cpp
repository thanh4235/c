// Xác định min và max trong mảng
#include <stdio.h>
int main()
{
    int mang[] = {5, 48, 64, 1, 78, 84, 156, 2};
    int kichthuoc = sizeof(mang) / sizeof(mang[0]);
    int min = mang[0], max = mang[0];
    for (int i = 1; i < kichthuoc; i++)
    {
        if (mang[i] < min)
            min = mang[i];
        if (mang[i] > max)
            max = mang[i];
    }

    printf("min: %d\nmax: %d", min, max);
    return 0;
}