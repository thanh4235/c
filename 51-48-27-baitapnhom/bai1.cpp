#include<stdio.h>
#include<math.h>
int main() {
float a,b,c,delta,x1,x2;
printf("nhap so a : ");
scanf("%f",&a);
printf("nhap so b : ");
scanf("%f", &b);
printf("nhap so c : ");
scanf("%f", &c);
printf("\n phuong trinh co dang: %0.0fx^2 + %0.0fx + %0.0f =0 ", a,b,c);
if (a ==0){
  if (b==0){
  if (c==0){
  printf("\n phuong trinh vo so nghiem. \n");
} else {
printf("\n phuong trinh vo nghiem. \n");
}
} else {
printf("\n phuong trinh co nghiem x = %.1f\n",-c/b);
}
}else{
delta = b*b - 4*a*c;
if(delta > 0 ){
x1=(-b + sqrt(delta)) / (2*a);
x2=(-b - sqrt(delta)) / (2*a);
printf("\n nghiem thu nhat x1 = %.1f \n",x1);
printf("\n nghiem thu hai x2 = %.1f \n",x2);
}else if (delta == 0){
printf("\n phuogn trinh co nghiem kep: x1 = x2 = %.1f \n",-b/2*a);
}else {
	printf("\n phuong trinh vo nghiem \n");
}
}
return 0;
}