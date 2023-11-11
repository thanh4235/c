/*Tìm ước chung lớn nhất của 2 số*/


#include<stdio.h>

int main() {
   int a, b, c, i;

   printf("Nhập số thứ nhất: ");
   scanf("%d",&a);
   printf("Nhập số thứ hai: ");
   scanf("%d",&b);

   for(i = 1; i <= a || i <= b; i++) {
   if( a%i == 0 && b%i == 0 )
      c = i;
   }

   printf("Ước chung lớn nhất của 2 số: %d", c);
   
   return 0;
}
