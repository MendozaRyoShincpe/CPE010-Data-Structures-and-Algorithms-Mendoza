#include <iostream>
#include <cmath>

class triangle {
private:
    double sideA, sideB, sideC;
    double angA, angB, angC;

public:
    triangle(double A, double B, double C,
             double sA, double sB, double sC);

    bool validateTriangle();
    double area();
    double pmtr();
    void trityp();
};

int main() {
    double angA, angB, angC;
    double sideA, sideB, sideC;
    int choice;

    std::cout << "Enter Angle A: ";
    std::cin >> angA;

    std::cout << "Enter Angle B: ";
    std::cin >> angB;

    std::cout << "Enter Angle C: ";
    std::cin >> angC;

    std::cout << "Enter Side A: ";
    std::cin >> sideA;

    std::cout << "Enter Side B: ";
    std::cin >> sideB;

    std::cout << "Enter Side C: ";
    std::cin >> sideC;

    triangle tri(angA, angB, angC, sideA, sideB, sideC);

    if (!tri.validateTriangle()) {
        std::cout << "\nThis is NOT a valid triangle.\n";
        return 0;
    }

    std::cout << "\n===== MENU =====\n";
    std::cout << "1. Compute Area\n";
    std::cout << "2. Compute Perimeter\n";
    std::cout << "3. Determine Triangle Type\n";
    std::cout << "Enter Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Area = " << tri.area() << std::endl;
            break;

        case 2:
            std::cout << "Perimeter = " << tri.pmtr() << std::endl;
            break;

        case 3:
            tri.trityp();
            break;

        default:
            std::cout << "Invalid Choice.\n";
    }

    return 0;
}

// Constructor
triangle::triangle(double A, double B, double C,
                   double sA, double sB, double sC) {
    angA = A;
    angB = B;
    angC = C;

    sideA = sA;
    sideB = sB;
    sideC = sC;
}

// Validate Triangle
bool triangle::validateTriangle() {

    if (angA <= 0 || angB <= 0 || angC <= 0)
        return false;

    if (sideA <= 0 || sideB <= 0 || sideC <= 0)
        return false;

    if (std::fabs((angA + angB + angC) - 180.0) > 0.001)
        return false;

    if (sideA + sideB <= sideC)
        return false;

    if (sideA + sideC <= sideB)
        return false;

    if (sideB + sideC <= sideA)
        return false;

    return true;
}

// Area using Heron's Formula
double triangle::area() {
    double s = (sideA + sideB + sideC) / 2.0;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

// Perimeter
double triangle::pmtr() {
    return sideA + sideB + sideC;
}

// Determine Triangle Type
void triangle::trityp() {

    if (angA < 90 && angB < 90 && angC < 90)
        std::cout << "The triangle is Acute-Angled.\n";

    else if (angA > 90 || angB > 90 || angC > 90)
        std::cout << "The triangle is Obtuse-Angled.\n";

    else
        std::cout << "The triangle is Others (Right Triangle).\n";
}