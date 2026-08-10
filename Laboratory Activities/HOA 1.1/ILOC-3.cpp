#include <iostream>
#include <cmath>

// Function prototype
double calculateDistance(double x1, double y1, double x2, double y2);

int main() {
    double x1, y1, x2, y2, distance;

    std::cout << "Enter the coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter the coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;

    // Function call
    distance = calculateDistance(x1, y1, x2, y2);

    std::cout << "\nThe distance between the two points is: " << distance << std::endl;

    return 0;
}

// Function definition
double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}