#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n, double p) : name(n), price(p) {}
};

class Receipt {
public:
    string customerName;
    int itemCount;
    double totalAmount;

    Receipt(string name, int count, double total)
        : customerName(name), itemCount(count), totalAmount(total) {}

    void print() const {
        cout << "Receipt for: " << customerName << endl;
        cout << "Items purchased: " << itemCount << endl;
        cout << "Total amount: " << totalAmount << endl;
    }
};

class Cart {
private:
    vector<Product> items;

public:
    // 1. Accepts a Product by const reference - avoids copying, does not modify the Product
    void addItem(const Product &product) {
        items.push_back(product); // a copy is stored inside the vector, which is normal here
    }

    // 2. Returns a reference to the internal items list,
    // allowing direct (careful) access without copying the whole vector
    vector<Product>& getItems() {
        return items;
    }

    // 3. Computes and returns a brand-new Receipt object by value
    Receipt checkout(string customerName) {
        double total = 0;
        for (const Product &p : items) { // reading each Product via const reference
            total += p.price;
        }
        return Receipt(customerName, items.size(), total);
    }
};

int main() {
    Cart cart;

    Product p1("Notebook", 3.5);
    Product p2("Pen", 1.2);
    Product p3("Backpack", 25.0);

    // Passing Product objects by const reference into addItem
    cart.addItem(p1);
    cart.addItem(p2);
    cart.addItem(p3);

    // Using the reference returned by getItems() to inspect items without copying the vector
    cout << "Number of items in cart: " << cart.getItems().size() << endl;

    // checkout() returns a brand-new Receipt object by value
    Receipt receipt = cart.checkout("Meena");
    receipt.print();

    return 0;
}