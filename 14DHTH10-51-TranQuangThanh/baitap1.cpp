#include <stdio.h>
#include <stdlib.h>

int main ()
{
int a,b,c,max; 
printf("Nhap a, b va c \n");
scanf("%d%d%d", &a, &b, &c);
max=a;

if (max>b&&max>c) {
printf("max=a=%d", a);
exit(0);
}

else if (b>max&&b>c) {
printf("max=b=%d", b);
exit(0);
}

else {
printf("max=c=%d", c);
}
   return(0);
}