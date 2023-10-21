#include <stdio.h>
int main(){
    int a,b,c,min,max;
    printf("nhap a: ");
    scanf("%d",&a);
    printf("nhap b: ");
    scanf("%d",&b);
    printf("nhap c: ");
    scanf("%d",&c);
    min=a<b?(a<c?a:c):(b<c?b:c);
    max=a>b?(a>c?a:c):(b>c?b:c);
    printf("min: %d\n", min);
    printf("max: %d", max);
}