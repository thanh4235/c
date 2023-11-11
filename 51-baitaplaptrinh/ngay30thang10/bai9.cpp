/*Bảng cửu chương từ 1 đến 10*/


#include<stdio.h>

int main() {
   int a, b, c, i;

   do {
  printf("Nhập một số bất kì từ 1 tới 10: ");
   scanf("%d",&a);
   if(a<=0||a>10)
   printf("Vui lòng nhập lại!!\n");}

  while (a<=0||a>10);

   for(i = 0; i<10; i++) {
      b = i + 1;
      c = a * b;
      printf("%d * %d = %d\n",a,b,c);
   }
   
   return 0;
}