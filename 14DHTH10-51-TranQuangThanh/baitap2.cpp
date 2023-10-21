#include <stdio.h>
#include <stdlib.h>

int main ()
{
int a; 
printf("Nhap so nguyen \n");
scanf("%d", &a);

if (a>0) {
printf("so nguyen duong", a);
exit(0);
}

else if (a<0) {
printf("so nguyen am", a);
exit(0);
}

else {
printf("ERROR", a);
}
   return(0);
}