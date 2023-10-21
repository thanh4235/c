#include<iostream>
int main (){
 double tensanpham, soluong, dongia, tien, thue;
 printf("Nhap tensanpham, soluong, dongia:");
 scanf("%lf%lf%lf",&tensanpham,&soluong,&dongia);
 tien = soluong*dongia;
 printf("Tien: %.3lf",tien);
 thue = (soluong*dongia)*0.1;
 printf("\nThue:%.3lf",thue);
 }
