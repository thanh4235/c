/*Tính tổng từ 1 đến 100 (while)*/

#include <stdio.h>
 
int main()
{
    int i=1, tong=0;

    while(i <= 100) 
    {
        tong = tong + i;
        i++;
    }
 
    printf("tổng từ 1 đến 100: %d\n", tong);
 
    return 0;
}