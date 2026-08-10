//Create a C++ program to swap the two numbers in different variables.

#include <iostream>

int main() {

    int a = 15;
    int b = 20;
    int swap;

    std::cout << "Before swapping: a = " << a << " b = " << b << std::endl;
    
    swap = a;
    a = b;
    b = swap;
    
    std::cout << "After swapping:  a = " << a << " b = " << b << std::endl;

    
    return 0; 
}