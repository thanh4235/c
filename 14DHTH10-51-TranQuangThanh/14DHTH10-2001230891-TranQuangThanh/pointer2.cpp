#include<stdio.h>

void input(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",arr+i);
    }
}
void display(int *arr, int size){
    printf("\nMang:");
    for(int i=0;i<size;i++){
        printf(" %d",*(arr+i));
    }
}
bool check_arr(int *arr, int n, int size){
    for(int i=0;i<size;i++)
    if(*(arr+i)==n)
    return true;
    return false;
}
void check(int *arr, int n, int size){
    printf("\nSo %d nam o cac vi tri:",n);
    for(int i=0;i<size;i++){
        if(*(arr+i)==n)
        printf(" %d",i+1);
    }
}
int main(){
    int size;
    do{
        printf("Nhap kich thuoc mang: ");
        scanf("%d",&size);
        if(size<0)
        printf("Gia tri khong hop le!!\n");
    } while(size<0);
    int arr[100], *p=arr;
    input(p,size);

    int n;
    printf("\nNhap so can tim: ");
    scanf("%d",&n);

    if(check_arr(arr,n,size))
    check(arr,n,size);
    else
    printf("\nKHONG CO\n");
    
    return 0;
}