#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double num = 12345.1244;
    cout << fixed << setprecision(3) << num << endl;
    cout << scientific << setprecision(3) << num << endl;
    return 0;
}