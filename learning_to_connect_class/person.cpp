// person.cpp
#include <iostream>
#include "person.h" // Includes the class definition

using namespace std;

void person::getdata(void) 
{
    cout << "Enter name : ";
    cin >> name;
    cout << "Enter age : ";
    cin >> age;
}

void person::display(void) 
{
    cout << "\nName: " << name;
    cout << "\nAge: " << age << endl;
}