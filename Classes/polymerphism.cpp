
#include <iostream>
using namespace std;

class Employee {
    protected:
        string name;

    public:
        Employee(string n) : name(n) {}

        virtual double calculateSalary() {
            return 30000; // generic base salary
        }

        virtual void display() {
            cout << name << "'s salary: " << calculateSalary() << endl;
        }

        virtual ~Employee() { // virtual destructor
            cout << "Employee destructor: " << name << endl;
        }
};

class Manager : public Employee {
    public:
        Manager(string n) : Employee(n) {}

        double calculateSalary() override {
            return 60000; // managers earn more
        }

        ~Manager() override {
            cout << "Manager destructor: " << name << endl;
        }
};

class Intern : public Employee {
    public:
        Intern(string n) : Employee(n) {}

        double calculateSalary() override {
            return 10000; // interns earn less
        }

        ~Intern() override {
            cout << "Intern destructor: " << name << endl;
        }
};

int main() {
    Employee *staff[3];

    staff[0] = new Employee("Generic Staff");
    staff[1] = new Manager("Aarav");
    staff[2] = new Intern("Priya");

    for (int i = 0; i < 3; i++) {
        staff[i]->display(); // late binding: correct calculateSalary() used each time
    }

    for (int i = 0; i < 3; i++) {
        delete staff[i]; // virtual destructor ensures correct cleanup
    }

    return 0;
}