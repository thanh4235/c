#include<stdio.h>
int main(){
    float toan,ly,hoa,min;

    printf("Nhập điểm toán: ");
    scanf("%f",&toan);
    if(toan<0||toan>10){
    printf("Giá trị không hợp lệ");
    return 0;}

    printf("Nhập điểm lý: ");
    scanf("%f",&ly);
    if(ly<0||ly>10){
    printf("Giá trị không hợp lệ");
    return 0;}

    printf("Nhập điểm hóa: ");
    scanf("%f",&hoa);
    if(hoa<0||hoa>10){
    printf("Giá trị không hợp lệ");
    return 0;}

    min=toan;
    if(ly<min)
    min=ly;
    if(hoa<min)
    min=hoa;

    if((toan+ly+hoa)>=15&&min>4)
    printf("Đậu\n");
    if((toan+ly+hoa)>=15&&min>5)
    printf("Học đều các môn");
    else if((toan+ly+hoa)>=15&&min<=5)
    printf("Học chưa đều các môn");
    else
    printf("Thi hỏng");
}