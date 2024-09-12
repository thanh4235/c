#include<stdio.h>

void input(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

void display(int arr[], int n){
    printf("\nXuat:");
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
}

int binarySearch(int arr[], int n, int k){
    int left=0, right=n-1, mid;
    while(left<=right){
        if((left+right)%2!=0){
        if(arr[mid]<k)
        left++;
        else if(arr[mid]>k)
        right--;
        }
        mid=(left+right)/2;
        if(arr[mid]==k)
        return mid;
        else if(arr[mid]<k)
        left=mid;
        else
        right=mid;
    }
    return -1;
}

int binarySearch2(int arr[], int n, int k){
        int left=0, right=n-1, mid;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==k)
        return mid;
        else if(arr[mid]<k)
        left=mid+1;
        else
        right=mid-1;
    }
    return -1;
}

int main(){
    int arr[100], n;
    printf("Nhap kich thuoc: ");
    scanf("%d",&n);

    input(arr,n);
    display(arr,n);
    printf("\n%d",binarySearch2(arr,n,2));
    return 0;
}