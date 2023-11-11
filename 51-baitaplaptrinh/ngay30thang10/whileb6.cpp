/*Tính tổng từ 1 đến n (while)*/

#include <stdio.h>
 
int main()
{
    int i=1,n, tong=0;

    printf("Nhập n: ");
    scanf("%d",&n);

    while(i<=n) 
    {
        tong = tong + i;
        i++;
    }
 
    printf("tổng từ 1 đến n: %d\n", tong);
 
    return 0;
}