/*Tìm ước chung lớn nhất của 2 số (while)*/


#include<stdio.h>

int main() {
   int a, b, c, i=1;

   printf("Nhập số thứ nhất: ");
   scanf("%d",&a);
   printf("Nhập số thứ hai: ");
   scanf("%d",&b);

   while(i <= a || i <= b) {
   if( a%i == 0 && b%i == 0 )
      c = i;
      i++;
   }

   printf("Ước chung lớn nhất của 2 số: %d", c);
   
   return 0;
}