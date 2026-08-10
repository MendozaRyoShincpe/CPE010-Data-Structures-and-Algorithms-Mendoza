#include <iostream>

// Function Prototype
int sumTwoNum(int first, int last);

int first, second;

int main() {
    
    std::cout << "Enter first number: ";
    std::cin >> first;
    std::cout << "Enter second number: ";
    std:: cin >> second;
    std::cout << "Total: " << sumTwoNum(first,second) << std::endl;

    return 0;
}

int sumTwoNum(int first, int last){

    int total = first + last;

    return total;
}