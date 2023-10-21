#include<stdio.h>
int main(){
    float F,C;
    printf("Nhap gia tri: ");
    scanf("%f",&F);
    C=(float)5/9*(F-32);
    printf("Doi ra do C: %f",C);
    return 0;
}