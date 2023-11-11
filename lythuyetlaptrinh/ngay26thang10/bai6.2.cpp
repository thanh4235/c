#include<stdio.h>
int main(){
    int a,b,c,tong,hieu,tich;
    float thuong;
    printf("Nhập a: ");
    scanf("%d",&a);
    printf("Nhập b: ");
    scanf("%d",&b);

    printf("(1) +\n(2) -\n(3) *\n(4) /\n\n");
    printf("Nhập một số từ 1 đến 4 để chọn phép tính: ");
    scanf("%d",&c);
    switch(c){
        case 1: tong=a+b; printf("%d + %d = %d",a,b,tong);break;
        case 2: hieu=a-b; printf("%d - %d = %d",a,b,hieu);break;
        case 3: tich=a*b; printf("%d * %d = %d",a,b,tich);break;
        case 4:if(b!=0){
        thuong=(float)a/b;
        printf("%d / %d = %f",a,b,thuong);
        }
        else
        printf("Không thể thực hiện phép tính");
        break;
        default:
        printf("Lỗi!! Vui lòng nhập một số từ 1 đến 4 để chọn phép tính");
    }
}