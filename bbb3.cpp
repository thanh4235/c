#include<iostream>
int main()
{
	int a, b;
	float x;
	printf("nhap 2 so nguyen a va b:");
	scanf("%d%d",&a, &b);
	if(a == 0 && b==0) {
		printf("vo so nghiem");
	}
	else if( a== 0 && b!= 0){
		printf("vo nghiem");
	}
	else{
	x=(float)-b/a;
	printf("phuong trinh co nghiem:%.2f",x);
	}
	return 0;
    
}

