#include <iostream>  
using namespace std;

int main ()
{
float a; 
printf("Nhập mức tiêu thụ điện trong tháng \n");
scanf("%f", &a);

if (a>300) {
int diff = (a-300)*20+(300-200)*15+(200-150)*10+(150-100)*7+100*5;
printf("tiền điện là ");
cout << diff << endl;
}

else if (a>200) {
int diff = (a-200)*15+(200-150)*10+(150-100)*7+100*5;
printf("tiền điện là ");
cout << diff << endl;
}

else if (a>150) {
int diff = (a-150)*10+(150-100)*7+100*5;
printf("tiền điện là ");
cout << diff << endl;
}

else if (a>100) {
int diff = (a-100)*7+100*5;
printf("tiền điện là ");
cout << diff << endl;
}

else if (a>0) {
int diff = a*5;
printf("tiền điện là ");
cout << diff << endl;
}

else {
printf("ERROR");
}

   return(0);
}