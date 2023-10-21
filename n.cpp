#include <stdio.h>
int main(){ int a,b,tong,hieu,tich,thuong;
    printf ("Nhap so nguyen thu nhat: ");
    scanf ("%d",&a);
    printf ("Nhap so nguyen thu hai: ");
    scanf ("%d",&b);
    tong=a+b;
    hieu=a-b;
    tich=a*b;
    thuong=(float)(a/b);
    printf ("tong: %d \n", tong);
    printf ("hieu: %d \n", hieu);
    printf ("tich: %d \n", tich);
    printf ("thuong: %d \n", thuong);
    return 0;
}