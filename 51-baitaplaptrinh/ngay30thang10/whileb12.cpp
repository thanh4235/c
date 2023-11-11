/* Tìm số nguyên dương m lớn nhất sao cho 1+2+...+m < N (while) */

#include <stdio.h>
 
int main()
{
    int i=1,n,a, tong=0;

    do {
    printf("Nhập n nguyên dương: ");
    scanf("%d",&n);
   if(n<0)
   printf("Vui lòng nhập lại!!\n");}
   while (n<0);

    while(i <= n) 
    {
        tong = tong + i;
        if(tong<n)
        a=i;
        i++;
    }
 
    printf("m=%d\n",a);
 
    return 0;
}