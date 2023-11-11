/*tất cả các số nguyên dương lẻ nhỏ hơn 100*/


#include<stdio.h>

int main() 
{
    int i;

   for(i = 1; i <= 100; i+=2) 
   {
        printf("%d\n",i);
    }
 
    return 0;
}