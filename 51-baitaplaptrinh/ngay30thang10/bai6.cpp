/*Tính tổng từ 1 đến n*/

#include <stdio.h>
 
int main()
{
    int i,n, tong=0;

    printf("Nhập n: ");
    scanf("%d",&n);

    for(i = 1; i <= n; i++) 
    {
        tong = tong + i;
    }
 
    printf("tổng từ 1 đến n: %d\n", tong);
 
    return 0;
}