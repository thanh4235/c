#include <stdio.h>
int main(){
    int a,b,c,d,e;
    float tbc;
    printf("Nhap so nguyen thu nhat: ");
    scanf("%d",&a);
    printf("Nhap so nguyen thu hai: ");
    scanf("%d",&b);
    printf("Nhap so nguyen thu ba: ");
    scanf("%d",&c);
    printf("Nhap so nguyen thu tu: ");
    scanf("%d",&d);
    printf("Nhap so nguyen thu nam: ");
    scanf("%d",&e);
    tbc=(float)(a+b+c+d+e)/5;
    printf("trung binh cong cua 5 so la: %f",tbc);
    return 0;
}