#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string fullName;
    cout << "Enter full name: ";
    getline(cin, fullName);

    stringstream iss(fullName);
    string firstName, middleName, mainName;

    iss >> firstName;

    iss >> middleName;

    getline(iss, mainName);

    cout << "First Name: " << firstName << endl;
    cout << "Middle Name: " << middleName << endl;
    cout << "Main Name: " << mainName << endl;

    return 0;
}