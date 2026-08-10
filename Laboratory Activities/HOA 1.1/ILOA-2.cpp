#include <iostream>

bool greaterThan(int A, int B);

int main(){

    int A, B;

    std::cout << "Enter value A: ";
    std::cin >> A;

    std::cout << "Enter value B: ";
    std::cin >> B;

    if (greaterThan(A,B)) {
        std::cout << "A is greater than B" << std::endl;
    } else {
        std::cout << "A is not greater than B" << std::endl;
    }

    return 0;
}

bool greaterThan (int A, int B) {

    return A > B;
}