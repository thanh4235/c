#include <iostream>
using namespace std;
int main() {
  int x;
  cout << "Nhap dtb mon: ";
  cin >> x;
  if ( x < 0 ) {
    cout<<"ERROR!";
    exit(0);
  }
  else if ( x > 10 ){
    cout<<"ERROR!";
    exit(0);
  }
  else if ( x >= 4 ){
    cout<<"DAU";
  }
  else {
    cout<<"ROT";
  }
  return 0;
}
