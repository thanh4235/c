#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int main(){
    char phep;
    int x,y,tong,hieu,tich,thuong;
    printf("nhap x="); scanf_s("%d",&x);
    printf("nhap y="); scanf_s("%d", &y);
    fflush(stdin);
    printf("nhap phep toan:"); scanf_s("%c",&phep);
    tong=x+y;
    hieu=x-y;
    tich=x*y;
    thuong=(float)x/y;
    switch(phep){
        case '+': printf("%d+%d=%d",x,y,tong);break;
        case '-': printf("%d-%d=%d",x,y,hieu);break;
        case '*': printf("%d*%d=%d",x,y,tich);break;
        if(y!=0)
        printf("%d/%d=%d",x,y,thuong);
        else
        printf("không chia được");
        break;
        default: printf("phép toán không tồn tại");
    }
_getch();


}