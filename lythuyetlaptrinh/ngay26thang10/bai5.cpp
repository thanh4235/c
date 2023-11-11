#include<stdio.h>
#include<math.h>
int main(){
    int a;
    float b,c,cvhv,dthv,cvhcn,dthcn,cvht,dtht;
    printf("(1) Hình vuông\n(2) Hình chữ nhật\n(3) Hình tròn\n");
    printf("Vui lòng chọn một số từ 1 đến 3 để chọn hình: ");
    scanf("%d",&a);

    switch(a){
        case 1:
        printf("Bạn chọn hình vuông\nNhập cạnh: ");
        scanf("%f",&b);
        cvhv=b*4;
        dthv=pow(b,2);
        printf("Chu vi: %f\n",cvhv);
        printf("Diện tích: %f",dthv);
        break;

        case 2:
        printf("Bạn chọn hình chữ nhật\nNhập chiều dài: ");
        scanf("%f",&b);
        printf("Nhập chiều rộng: ");
        scanf("%f",&c);
        cvhcn=(b+c)*2;
        dthcn=b*c;
        printf("Chu vi: %f\n",cvhcn);
        printf("Diện tích: %f",dthcn);
        break;

        case 3:
        printf("Bạn chọn hình tròn\nNhập bán kính: ");
        scanf("%f",&b);
        cvht=2*b*M_PI;
        dtht=pow(b,2)*M_PI;
        printf("Chu vi: %f\n",cvht);
        printf("Diện tích: %f",dtht);
        break;

        default:
        printf("Lỗi!! Vui lòng nhập 1 số từ 1 đến 3");
        return 0;

    }
    
}