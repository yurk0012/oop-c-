#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Product {
    string name;
    int quantity;
    double price;

public:
    
    Product(string n = "", int q = 0, double p = 0) {
        setName(n); setQuantity(q); setPrice(p);
    }

    void setName(string n) { name = n; }
    void setQuantity(int q) {
        if (q < 0) throw invalid_argument("Quantity cannot be negative!");
        quantity = q;
    }
    void setPrice(double p) {
        if (p < 0) throw invalid_argument("Price cannot be negative!");
        price = p;
    }

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    Product& operator++() { quantity++; return *this; }
    Product& operator--() {
        if (quantity == 0) throw out_of_range("Quantity cannot be less than 0!");
        quantity--;
        return *this;
    }
    Product& operator=(const Product& p) {
        if (this != &p) { name = p.name; quantity = p.quantity; price = p.price; }
        return *this;
    }

   
    void show() const {
        cout << "Name: " << name << " | Quantity: " << quantity << " | Price: " << price << endl;
    }
};

class Warehouse {
    Product arr[100];
    int count = 0;

public:
    void add(const Product& p) {
        if (count >= 100) throw overflow_error("Warehouse is full!");
        arr[count++] = p;
    }

    void showAll() const {
        if (!count) cout << "Warehouse is empty!\n";
        else for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            arr[i].show();
        }
    }

    void searchByName(string n) const {
        bool found = false;
        for (int i = 0; i < count; i++)
            if (arr[i].getName() == n) { arr[i].show(); found = true; }
        if (!found) cout << "Product not found!\n";
    }

    Product& getProduct(int index) { return arr[index]; }
    int getCount() const { return count; }
};

int main() {
    setlocale(LC_ALL, "English");
    Warehouse warehouse;

    try {
        int n;
        cout << "How many products to add? "; cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            string name; int q; double p;
            cout << "\nEnter product name: "; getline(cin, name);
            cout << "Quantity: "; cin >> q;
            cout << "Price: "; cin >> p;
            cin.ignore();
            warehouse.add(Product(name, q, p));
        }

        cout << "\n--- All products in warehouse ---\n";
        warehouse.showAll();

        cout << "\nSearch product by name: ";
        string name; getline(cin, name);
        warehouse.searchByName(name);

        cout << "\nChoose product number for ++ or -- : ";
        int num; cin >> num;
        if (num > 0 && num <= warehouse.getCount()) {
            cout << "1 - ++, 2 - -- : "; int op; cin >> op;
            if (op == 1) ++warehouse.getProduct(num - 1);
            else if (op == 2) --warehouse.getProduct(num - 1);
            warehouse.getProduct(num - 1).show();
        }

        cout << "\nCopying product 1 to product 2 (=):\n";
        if (warehouse.getCount() >= 2) {
            warehouse.getProduct(1) = warehouse.getProduct(0);
            warehouse.showAll();
        }

    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
