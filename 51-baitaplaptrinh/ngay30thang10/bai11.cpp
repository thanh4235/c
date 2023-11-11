/*tổng các giá trị lẻ nguyên dương nhỏ hơn n*/


#include<stdio.h>

int main() 
{
    int i,n,a, tong=0;

    do {
    printf("Nhập n nguyên dương: ");
    scanf("%d",&n);
   if(n<0)
   printf("Vui lòng nhập lại!!\n");}
   while (n<0);

   for(i = 1; i <= n; i+=2) 
   {
        tong = tong + i;
        if(tong<n)
        a=tong;
    }
 
    printf("Tổng các giá trị lẻ nguyên dương nhỏ hơn n: %d\n",a);
 
    return 0;
}