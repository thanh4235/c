#include <iostream>
#include <cmath>
using namespace std; 
 
int main()
{
    int a,b,c;
 
    cout << "KIỂM TRA a CÓ LÀ BỘI SỐ CỦA b KHÔNG" << endl;
    cout << "Nhập a (khác 0): " ;
    cin >> a;
    if (a==0){
        cout << "Vui lòng nhập a là số khác 0" << endl;
        exit (0);
    }
    cout << "Nhập b (khác 0): " ;
    cin >> b;
    if (b==0){
        cout << "Vui lòng nhập b là số khác 0" << endl;
        exit (0);
    }
    c=a%b;
    if (c==0){
        cout << "a là bội số của b" << endl;
    }
    else {
        cout << "a không phải là bội số của b" << endl;
    }
 
    return 0;
}