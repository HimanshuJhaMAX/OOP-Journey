#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main () 
{
    cout  << left ;
    string full_name , last_name;
    cout << "Enter the first name:" << endl;
    getline(cin, full_name);
    cout << "Enter the last name:" << endl;
    getline(cin, last_name);
    cout << setfill('_') << setw(10) << full_name << setw(10) << last_name << endl;
    return 0;
}