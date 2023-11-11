/*Tuổi cha gấp đôi tuổi con*/


#include<stdio.h>

int main() {
   int a, b, c, d, e, f, g, i;
   
   printf("Nhập số năm hiện tại: ");
   scanf("%d",&a);
   
   printf("Nhập tuổi con: ");
   scanf("%d",&c);

   do {
  printf("Nhập tuổi cha: ");
   scanf("%d",&b);
   if(b-c<20){
   printf("Tuổi cha phải lớn hơn tuổi con ít nhất 20 tuổi\n");
   printf("Vui lòng nhập lại!!\n");}
      }
  while (b-c<20);   

   for(i = 0; i <= 1000; i++) {

      f = b + i;
      g = c + i;
      if(f/g==2)
         d=i;

   }

   e=a+d;
   printf("Đến năm %d thì tuổi cha gấp đôi tuổi con", e);
   
   return 0;
}