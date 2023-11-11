/*Tính tổng từ 1 đến 100*/

#include <stdio.h>
 
int main()
{
    int i, tong=0;

    for(i = 1; i <= 100; i++) 
    {
        tong = tong + i;
    }
 
    printf("tổng từ 1 đến 100: %d\n", tong);
 
    return 0;
}