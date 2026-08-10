#include <iostream>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;

public:
    // Constructor
    Triangle(double A, double B, double C);

    // Setter method
    void setAngles(double A, double B, double C);

    // Validation method
    const bool validateTriangle();
};

// Constructor definition
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Setter definition
void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Validation definition
const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

// Driver code
int main() {
    Triangle set1(40, 30, 110);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}