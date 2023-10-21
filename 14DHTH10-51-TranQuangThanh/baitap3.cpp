#include <stdio.h>
#include <stdlib.h>

int main ()
{
int a,b; 
printf("Nhap 2 so nguyen a,b bat ki \n");
scanf("%d%d", &a, &b);

if (a>b) {
printf(" a lon hon b");
exit(0);
}

else if (a<b) {
printf("a nho hon b");
exit(0);
}

else {
printf("a bang b");
}
   return(0);
}