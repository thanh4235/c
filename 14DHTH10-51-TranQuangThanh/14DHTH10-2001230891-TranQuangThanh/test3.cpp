#include<stdio.h>
#include<string.h>
struct student{
    char code[100];
    char name[100];
    int absence;
};
void terminateNewLine(char *a){
    char *newline=strchr(a,'\n');
    if(newline!=NULL)
    *newline='\0';
}
void nhap(struct student a[],int n){
    for(int i=0;i<n;i++){
        printf("\nNHAP THONG TIN SINH VIEN THU %d\n",i+1);
        printf("Nhap ma thu nhat: ");
        getchar();
        fgets(a[i].code,sizeof a[i].code, stdin);
        terminateNewLine(a[i].code);

        printf("Nhap ten thu nhat: ");
        fgets(a[i].name,sizeof a[i].name,stdin);
        terminateNewLine(a[i].name);

        printf("Nhap so ngay vang: ");
        scanf("%d",&a[i].absence);
    }
}
int main(){
    struct student a[100];
    int n;
    printf("Nhap so luong: ");
    scanf("%d",&n);
    nhap(a,n);
}