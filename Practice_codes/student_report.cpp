// Program: To Display a Formatted Student Report Using Manipulators

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    string students[] = {"Aarav Sharma", "Priya Thapa", "Rohan KC", "Sita Rai"};
    double marks[]    = {85.5, 92.0, 78.75, 65.25};
    int    n          = 4;
    double total      = 0;

    // Table header
    cout << setfill('=') << setw(45) << "" << endl;
    cout << setfill(' ');
    cout << left  << setw(20) << "Student Name"
         << right << setw(12) << "Marks"
         << right << setw(10) << "Grade"
         << endl;
    cout << setfill('=') << setw(45) << "" << endl;
    cout << setfill(' ');

    // Table rows
    for (int i = 0; i < n; i++) {
        string grade;
        if      (marks[i] >= 90) grade = "A";
        else if (marks[i] >= 80) grade = "B";
        else if (marks[i] >= 70) grade = "C";
        else if (marks[i] >= 60) grade = "D";
        else                     grade = "F";

        cout << left  << setw(20) << students[i]
             << right << setw(12) << fixed << setprecision(2) << marks[i]
             << right << setw(10) << grade
             << endl;

        total += marks[i];
    }

    // Footer
    cout << setfill('-') << setw(45) << "" << endl;
    cout << setfill(' ');
    cout << left  << setw(20) << "Class Average"
         << right << setw(12) << fixed << setprecision(2) << total / n
         << endl;
    cout << setfill('=') << setw(45) << "" << endl;

    return 0;
}