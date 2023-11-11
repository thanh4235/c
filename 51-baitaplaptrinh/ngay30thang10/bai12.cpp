/* Tìm số nguyên dương m lớn nhất sao cho 1+2+...+m < N */

#include <stdio.h>
 
int main()
{
    int i,n,a, tong=0;

    do {
    printf("Nhập n nguyên dương: ");
    scanf("%d",&n);
   if(n<0)
   printf("Vui lòng nhập lại!!\n");}
   while (n<0);

    for(i = 1; i <= n; i++) 
    {
        tong = tong + i;
        if(tong<n)
        a=i;

    }
 
    printf("m=%d\n",a);
 
    return 0;
}