// Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.

#include <iostream>

bool logicalOperators(bool A, bool B);

int main() {
    
    bool A, B;
    
    std::cout << "Enter between 0 and 1" << std::endl;
    std::cout << "Boolean(A): ";
    std::cin >> A;
    std::cout << "Boolean(B): ";
    std::cin >> B;

    if (logicalOperators(A, B)) {
        std::cout << "\nLogical operations completed successfully." << std::endl;
    }

    return 0;

}

 bool logicalOperators(bool A, bool B) {

    std::cout << "AND (&&): " << (A && B) << std::endl;
    std::cout << "OR (||): " << (A || B) << std::endl;
    std::cout << "A NOT(!): " << (!A) << std::endl;
    std::cout << "B NOT(!): " << (!B) << std::endl;

    return true;
 }