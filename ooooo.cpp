#include <iomanip>
#include <iostream>  
using namespace std;

int main ()
{
int a,b,c,d,e;
cout << "Input time (s): ";
cin >> a;

b=a/60;c=a%60;
d=c/60;e=c%60;

cout <<  std::setfill('0') << setw(2) << b << " : " << setfill('0') << setw(2) << d << " : " << setfill('0') << setw(2) << e << endl;

   return(0);
}