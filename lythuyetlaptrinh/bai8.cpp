#include<stdio.h>
int main(){
    int a,b,max;
    printf("Nhap so nguyen thu nhat: ");
    scanf("%d",&a);
    printf("Nhap so nguyen thu hai: ");
    scanf("%d",&b);
    max=a>b?a:b;
    printf("\nSo lon nhat la: %d",max);
    return 0;
}