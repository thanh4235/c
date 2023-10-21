#include<stdio.h>
#include<math.h>
int main(){
    float r,chuvi,dientich;
    printf("Nhap ban kinh hinh tron (cm): ");
    scanf("%f",&r);
    chuvi=M_PI*r*2;
    dientich=M_PI*pow(r,2);
    printf("Chu vi: %f cm\n",chuvi);
    printf("Dien tich: %f cm^2\n",dientich);
    return 0;
}