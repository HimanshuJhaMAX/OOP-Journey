// Program: Dynamic Student Record System

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    int n;
    cout << "Enter number of students: ";
    cin  >> n;
    cin.ignore();

    // Dynamically allocate arrays for names and marks
    string* names = new string[n];
    double* marks = new double[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << (i + 1) << endl;
        cout << "  Name  : ";
        getline(cin, names[i]);
        cout << "  Marks : ";
        cin  >> marks[i];
        cin.ignore();
    }

    // Output
    cout << "\n" << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ');
    cout << left  << setw(22) << "Name"
         << right << setw(8)  << "Marks"
         << right << setw(8)  << "Grade"
         << endl;
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ');

    double total = 0;
    for (int i = 0; i < n; i++) {
        string grade;
        if      (marks[i] >= 90) grade = "A";
        else if (marks[i] >= 80) grade = "B";
        else if (marks[i] >= 70) grade = "C";
        else if (marks[i] >= 60) grade = "D";
        else                     grade = "F";

        cout << left  << setw(22) << names[i]
             << right << setw(8)  << fixed << setprecision(1) << marks[i]
             << right << setw(8)  << grade
             << endl;

        total += marks[i];
    }

    cout << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ');
    cout << left  << setw(22) << "Average"
         << right << setw(8)  << fixed << setprecision(1) << total / n
         << endl;
    cout << setfill('=') << setw(40) << "" << endl;

    // Free dynamically allocated memory
    delete[] names;
    delete[] marks;
    names = nullptr;
    marks = nullptr;

    return 0;
}
