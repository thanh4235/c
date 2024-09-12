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
void swap(int *arr1, int size, int *arr2){
	int j=size-1;
	for(int i=0;i<size;i++){
		*(arr2+j)=*(arr1+i);
		j--;
	}
	for(int i=0;i<size;i++){
		*(arr1+i)=*(arr2+i);
	}
}
void arrangement(int *arr, int size){
	int temp;
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(*(arr+i)<*(arr+j)){
			temp=*(arr+i);
			*(arr+i)=*(arr+j);
			*(arr+j)=temp;
			}
		}
	}
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

	int arr2[100],*p2=arr2;

    input(p,size);

	arrangement(p,size);

	display(p,size);
    
    return 0;
}