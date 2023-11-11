#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    printf("KARAOKE HOẠT ĐỘNG TỪ 10-24H\n");
    printf("Nhập thời gian bắt đầu (GIỜ:PHÚT): ");
    scanf("%d",&a);
    if (a<10){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }

        else if (a>=24){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }

    printf("%d:",a);
    scanf("%d",&b);
        if (b<0){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }
        else if (b>=60){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }

        else if (b<10){
            printf("\nThời gian bắt đầu: %d",a);
            printf(":0%d\n\n",b);
        }

        else {
            printf("\nThời gian bắt đầu: %d",a);
            printf(":%d\n\n",b);
        }

    printf("Nhập thời gian trả phòng (GIỜ:PHÚT): ");
    scanf("%d",&c);
        if (c<10){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }

        else if (c>=24){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }

    printf("%d:",c);
    scanf("%d",&d);
        if (d<0){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }
        else if (d>=60){
        printf("Lỗi!!\nThời gian không hợp lệ");
        return 0;
        }

        else if (d<10){
            printf("\nThời gian trả phòng: %d",c);
            printf(":0%d\n\n",d);
        }

        else {
            printf("\nThời gian trả phòng: %d",c);
            printf(":%d\n\n",d);
        }

        if ((a+b/60)<=17){
            if ((c+d/60)<17){
                e=((c+((double)d/60))-(a+((double)b/60)))*20000;
                printf("\nTổng tiền: %d đồng",e);
                return 0;
            }
            if ((c+d/60)>17){
                f=(((c+(double)d/60)-17)*45000)+((17-(a+(double)b/60))*20000);
                printf("\nTổng tiền: %d đồng",f);
                return 0;
            }
        }
        else {
            g=((c+(double)d/60)-(a+(double)b/60))*45000;
            printf("\nTổng tiền: %d đồng",g);
        }

    return 0;
}