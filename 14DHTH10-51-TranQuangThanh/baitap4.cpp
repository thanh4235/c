#include <iostream>
using namespace std; 
 
int main()
{
    int a;
 
    cout << "Nhập số thứ tự tháng: ";
    cin >> a;
 
    switch(a) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Tháng " << a  << " có 31 ngày" << endl;
            break;
        case 2: 
            cout << "Tháng " << a  << " có 28 hoặc 29 ngày" << endl;
            break;
        case 4: 
        case 6: 
        case 9:
        case 11: 
             cout << "Tháng " << a  << " có 30 ngày" << endl;
            break;
        default: 
            cout << "Lỗi!!" << endl;
            cout << "Vui lòng nhập số từ 1 đến 12" << endl;
    }
    return 0;
}