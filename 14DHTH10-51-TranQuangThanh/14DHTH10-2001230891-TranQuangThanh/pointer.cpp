#include<stdio.h>

void input(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",arr+i);
    }
}
int min(int *arr,int size){
    int min=*arr;
    for(int i=1;i<size;i++){
        if(min>*(arr+i)){
            min=*(arr+i);
        }
    }
    return min;
}
void display(int *arr,int size){
    printf("\nMang:");
    for(int i=0;i<size;i++){
        printf(" %d",*(arr+i));
    }
}
int main(){
    int size,arr[100],*p=arr;
    printf("Nhap kich thuoc mang: ");
    scanf("%d",&size);

    input(arr,size);
    printf("\nGia tri nho nhat: %d\n",min(arr,size));

    return 0;
}