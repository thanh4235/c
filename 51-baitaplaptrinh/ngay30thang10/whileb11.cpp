/*tổng các giá trị lẻ nguyên dương nhỏ hơn n (while)*/


#include<stdio.h>

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
        a=tong;
        i+=2;
    }
 
    printf("Tổng các giá trị lẻ nguyên dương nhỏ hơn %d: %d\n",n,a);
 
    return 0;
}