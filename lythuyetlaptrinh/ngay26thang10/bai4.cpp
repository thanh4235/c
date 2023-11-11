#include<stdio.h>
int main(){
    int a;
    printf("Nhập 1 số bất kì từ 0 đến 9: ");
    scanf("%d",&a);
    switch(a){
        case 0:
        printf("không");
        break;
        case 1:
        printf("một");
        break;
        case 2:
        printf("hai");
        break;
        case 3:
        printf("ba");
        break;
        case 4:
        printf("bốn");
        break;
        case 5:
        printf("năm");
        break;
        case 6:
        printf("sáu");
        break;
        case 7:
        printf("bảy");
        break;
        case 8:
        printf("tám");
        break;
        case 9:
        printf("chín");
        break;
        default:
        printf("Lỗi!! Vui lòng nhập 1 số bất kì từ 0 đến 9");
    }
}