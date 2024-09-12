#include <iostream>
#include <string>

using namespace std;

int main()
{
    int arr[100], n;
    do
    {
        cout << "Nhap kich thuoc mang: ";
        cin >> n;
        if (n < 0)
        {
            cout << "Khong hop le!!" << endl;
        }
    } while (n < 0);

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Sau khi sap xep:";
    for (int i; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}