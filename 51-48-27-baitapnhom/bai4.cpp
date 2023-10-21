#include <iostream>
#include <cmath>
using namespace std; 
 
int main()
{
    int a,b,c,d;
 
    cout << "KARAOKE HOẠT ĐỘNG TỪ 10-24H" << endl;
    cout << "Thời gian bắt đầu (GIỜ:PHÚT): " ;
    cin >> a;
        if (a<10){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }

        else if (a>=24){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }

    cout << a << ":" ;
    cin >> b;
        if (b<0){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }
        else if (b>=60){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }

        else if (b<10){
            cout << "Thời gian bắt đầu: " << a << ":0" << b << endl;
        }

        else {
            cout << "Thời gian bắt đầu: " << a << ":" << b << endl;
        }

    cout << "Thời gian trả phòng (GIỜ:PHÚT): " ;
    cin >> c;
        if (c<10){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }

        else if (c>=24){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }

    cout << c << ":" ;
    cin >> d;
        if (d<0){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }
        else if (d>=60){
        cout << "Lỗi!!" << endl;
        cout << "Thời gian không hợp lệ" << endl;
        exit (0);
        }

        else if (d<10){
            cout << "Thời gian trả phòng: " << c << ":0" << d << endl;
        }

        else {
            cout << "Thời gian trả phòng: " << c << ":" << d << endl;
        }

        if ((a+b/60)<=17){
            if ((c+d/60)<17){
                cout << "Tổng tiền: " << ((c+((double)d/60))-(a+((double)b/60)))*20000 << " đồng" << endl;
                exit(0);
            }
            if ((c+d/60)>17){
                cout << "Tổng tiền: " << (((c+(double)d/60)-17)*45000)+((17-(a+(double)b/60))*20000) << " đồng" << endl;
                exit(0);
            }
        }
        else {
            cout << "Tổng tiền: " << ((c+(double)d/60)-(a+(double)b/60))*45000 << " đồng" << endl;
        }

    return 0;
}