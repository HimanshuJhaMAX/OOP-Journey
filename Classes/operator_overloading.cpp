#include <iostream>
using namespace std;

class Vector2D {
private:
    double coords[2]; // coords[0] = x, coords[1] = y

public:
    Vector2D(double x = 0, double y = 0) {
        coords[0] = x;
        coords[1] = y;
    }

    // 1. Binary arithmetic operator: adds two vectors, returns a new Vector2D
    Vector2D operator+(const Vector2D &other) const {
        return Vector2D(coords[0] + other.coords[0], coords[1] + other.coords[1]);
    }

    // 2. Comparison operator: returns true if both components match
    bool operator==(const Vector2D &other) const {
        return coords[0] == other.coords[0] && coords[1] == other.coords[1];
    }

    // 3. Unary operator: negates both components
    Vector2D operator-() const {
        return Vector2D(-coords[0], -coords[1]);
    }

    // 4. Prefix increment: increases both components by 1, returns updated object
    Vector2D& operator++() {
        coords[0]++;
        coords[1]++;
        return *this;
    }

    // 5. Postfix increment: returns the original value, then increases both components
    Vector2D operator++(int) {
        Vector2D temp = *this;
        coords[0]++;
        coords[1]++;
        return temp;
    }

    // 6. Subscript operator: allows indexed access to components, e.g. v[0]
    double& operator[](int index) {
        return coords[index];
    }

    // 7. Assignment operator: copies components with a self-assignment guard
    Vector2D& operator=(const Vector2D &other) {
        if (this != &other) {
            coords[0] = other.coords[0];
            coords[1] = other.coords[1];
        }
        return *this;
    }

    void display() const {
        cout << "(" << coords[0] << ", " << coords[1] << ")" << endl;
    }
};

int main() {
    Vector2D v1(2, 3);
    Vector2D v2(4, 1);

    // Using operator+
    Vector2D v3 = v1 + v2;
    cout << "v1 + v2 = ";
    v3.display();

    // Using operator==
    Vector2D v4(2, 3);
    cout << "v1 == v4? " << (v1 == v4) << endl;

    // Using unary operator-
    Vector2D v5 = -v1;
    cout << "-v1 = ";
    v5.display();

    // Using prefix and postfix ++
    Vector2D v6(1, 1);
    ++v6;
    cout << "After ++v6: ";
    v6.display();

    Vector2D v7 = v6++;
    cout << "v7 (before v6's postfix ++): ";
    v7.display();
    cout << "v6 (after postfix ++): ";
    v6.display();

    // Using operator[]
    cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << endl;
    v1[0] = 100; // modifying through the reference returned by operator[]
    cout << "v1 after v1[0] = 100: ";
    v1.display();

    // Using operator=
    Vector2D v8;
    v8 = v1; // custom assignment operator
    cout << "v8 after v8 = v1: ";
    v8.display();

    return 0;
}