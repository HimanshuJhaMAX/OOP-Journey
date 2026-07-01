#include<iostream>
#include<iomanip>
using namespace std;

int main() 
{
    double pi = 3.14159265358979;

    cout << pi                            << endl;   // 3.14159  (default)
    cout << setprecision(3) << pi         << endl;   // 3.14
    cout << setprecision(7) << pi         << endl;   // 3.141593
    cout << fixed << setprecision(2) << pi << endl;  // 3.14
    return 0;
}