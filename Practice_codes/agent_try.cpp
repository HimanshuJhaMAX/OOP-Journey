// Program: Dynamic Student Record System (Class-based)

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double marks;

public:
    Student() : name(""), marks(0.0) {}

    Student(const string& studentName, double studentMarks)
        : name(studentName), marks(studentMarks) {}

    void readInput(int index) {
        cout << "\nStudent " << (index + 1) << endl;
        cout << "  Name  : ";
        getline(cin, name);
        cout << "  Marks : ";
        cin >> marks;
        cin.ignore();
    }

    string getGrade() const {
        if      (marks >= 90) return "A";
        else if (marks >= 80) return "B";
        else if (marks >= 70) return "C";
        else if (marks >= 60) return "D";
        else                    return "F";
    }

    void displayRow() const {
        cout << left  << setw(22) << name
             << right << setw(8)  << fixed << setprecision(1) << marks
             << right << setw(8)  << getGrade()
             << endl;
    }

    double getMarks() const { return marks; }
};

class StudentReport {
private:
    Student* students;
    int count;

    void displayHeader() const {
        cout << "\n" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ');
        cout << left  << setw(22) << "Name"
             << right << setw(8)  << "Marks"
             << right << setw(8)  << "Grade"
             << endl;
        cout << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ');
    }

    void displayFooter(double average) const {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << setfill(' ');
        cout << left  << setw(22) << "Average"
             << right << setw(8)  << fixed << setprecision(1) << average
             << endl;
        cout << setfill('=') << setw(40) << "" << endl;
    }

    double calculateAverage() const {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += students[i].getMarks();
        }
        return total / count;
    }

public:
    StudentReport(int studentCount) : count(studentCount) {
        students = new Student[count];
    }

    ~StudentReport() {
        delete[] students;
        students = nullptr;
    }

    void readInput() {
        for (int i = 0; i < count; i++) {
            students[i].readInput(i);
        }
    }

    void displayReport() const {
        displayHeader();

        for (int i = 0; i < count; i++) {
            students[i].displayRow();
        }

        displayFooter(calculateAverage());
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    StudentReport report(n);
    report.readInput();
    report.displayReport();

    return 0;
}
