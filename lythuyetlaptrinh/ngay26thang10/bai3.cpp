#include<stdio.h>
int main(){
    float a,b,x;
    printf("Nhap a: ");
    scanf("%f", &a);
    printf("Nhap b: ");
    scanf("%f", &b);
    if(a==0&&b==0){
        printf("phuong trinh vo so nghiem");

    }
    else if(a==0&&b!=0){
        printf("phuong trinh vo nghiem");
        
    }
    else{
        x=-b/a;
        printf("x=%f",x);
    }
}