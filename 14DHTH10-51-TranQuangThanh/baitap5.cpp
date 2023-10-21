#include <iostream>
#include <cmath>
using namespace std; 
 
int main()
{
    int a,b,c;
 
    cout << "Vui lòng chọn hình mà bạn muốn tính: " << endl;
    cout << "(Nhập 1 để chọn hình vuông)" << endl;
    cout << "(Nhập 2 để chọn hình chữ nhật)" << endl;
    cout << "(Nhập 3 để chọn hình tròn)" << endl;
    cin >> a;
 
    switch(a) {
        case 1:
            cout << "Tính chu vi và diện tích HÌNH VUÔNG: " << endl;
            cout << "Nhập chiều dài cạnh (cm): ";
            cin >> b;
            cout << "Chu vi HÌNH VUÔNG là: " << b*4  << " cm" << endl;
            cout << "Diện tích HÌNH VUÔNG là: " << pow(b,2)  << " cm^2" << endl;
            break;
        case 2: 
            cout << "Tính chu vi và diện tích HÌNH CHỮ NHẬT " << endl;
            cout << "Nhập chiều dài cạnh (cm): ";
            cin >> b;
            cout << "Nhập chiều rộng cạnh (cm): ";
            cin >> c;
            cout << "Chu vi HÌNH CHỮ NHẬT là: " << (b+c)*2  << " cm" << endl;
            cout << "Diện tích HÌNH CHỮ NHẬT là: " << b*c  << " cm^2" << endl;
            break;
        case 3: 
             cout << "Tính chu vi và diện tích HÌNH TRÒN " << endl;
             cout << "Nhập bán kính (cm): ";
             cin >> b;
            cout << "Chu vi HÌNH TRÒN là: " << M_PI*2*b  << " cm" << endl;
            cout << "Diện tích HÌNH TRÒN là: " << M_PI*pow(b,2)  << " cm^2" << endl;
            break;
        default: 
            cout << "Lỗi!!" << endl;
            cout << "Hình không hợp lệ." << endl;
    }
    return 0;
}