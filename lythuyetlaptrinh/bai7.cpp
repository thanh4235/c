#include<stdio.h>
#include<math.h>
int main(){
    float a,chuvi,dientich,duongcheo;
    printf("Nhap chieu dai canh a: ");
    scanf("%f",&a);
    chuvi=a*4;
    dientich=pow(a,2);
    duongcheo=a*sqrt(2);
    printf("Chu vi hinh vuong: %f\n",chuvi);
    printf("Dien tich hinh vuong: %f\n",dientich);
    printf("Duong cheo hinh vuong: %f",duongcheo);
}