#include <iostream>
#include <string>

//================== FRUIT CLASS ==================
class Fruit {
private:
    std::string name;
    int price;
    int quantity;

public:
    // Constructor
    Fruit(std::string n = "", int p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Fruit() {
        std::cout << "Fruit " << name << " destroyed." << std::endl;
    }

    // Copy Constructor
    Fruit(const Fruit& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Calculate total price
    int calculateSum() {
        return price * quantity;
    }

    // Display information
    void display() {
        std::cout << "Type: Fruit" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: PHP " << calculateSum() << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
};

//================== VEGETABLE CLASS ==================
class Vegetable {
private:
    std::string name;
    int price;
    int quantity;

public:
    // Constructor
    Vegetable(std::string n = "", int p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Vegetable() {
        std::cout << "Vegetable " << name << " destroyed." << std::endl;
    }

    // Copy Constructor
    Vegetable(const Vegetable& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Calculate total price
    int calculateSum() {
        return price * quantity;
    }

    // Display information
    void display() {
        std::cout << "Type: Vegetable" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: PHP " << calculateSum() << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
};

//================== TOTAL SUM FUNCTION ==================
int TotalSum(Fruit* fruits[], int fruitCount,
             Vegetable* vegetables[], int vegetableCount) {

    int total = 0;

    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != nullptr) {
            total += fruits[i]->calculateSum();
        }
    }

    for (int i = 0; i < vegetableCount; i++) {
        if (vegetables[i] != nullptr) {
            total += vegetables[i]->calculateSum();
        }
    }

    return total;
}

//================== MAIN FUNCTION ==================
int main() {

    // Grocery List
    Fruit* fruits[2];
    Vegetable* vegetables[2];

    // Create objects
    fruits[0] = new Fruit("Apple", 10, 7);
    fruits[1] = new Fruit("Banana", 10, 8);

    vegetables[0] = new Vegetable("Broccoli", 60, 12);
    vegetables[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "===== Jenna's Grocery List =====" << std::endl << std::endl;

    // Display Fruits
    for (int i = 0; i < 2; i++) {
        fruits[i]->display();
    }

    // Display Vegetables
    for (int i = 0; i < 2; i++) {
        vegetables[i]->display();
    }

    // Display Total Amount
    std::cout << "Total Amount to Pay: PHP "
              << TotalSum(fruits, 2, vegetables, 2)
              << std::endl << std::endl;

    // Delete Lettuce
    std::cout << "Deleting Lettuce..." << std::endl;

    delete vegetables[1];
    vegetables[1] = nullptr;

    std::cout << std::endl;

    // Display Updated Total
    std::cout << "Updated Total: PHP "
              << TotalSum(fruits, 2, vegetables, 2)
              << std::endl << std::endl;

    // Delete remaining objects
    delete fruits[0];
    delete fruits[1];
    delete vegetables[0];

    return 0;
}