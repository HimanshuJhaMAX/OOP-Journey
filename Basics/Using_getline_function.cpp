#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;
    string address;

    cout << "Enter full name : ";
    getline(cin, fullName);

    cout << "Enter address   : ";
    getline(cin, address);

    cout << "\nName    : " << fullName << endl;
    cout << "Address : " << address   << endl;

    return 0;
}