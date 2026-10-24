//Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit.
#include <iostream>

double kelvinToFahrenheit (double kelvin);

int main() {
    
    double kelvin;

    std::cout << "Enter Kelvin to convert in Fahrenheit: ";
    std::cin >> kelvin;

    std::cout << "Fahrenheit: " << kelvinToFahrenheit(kelvin);

    return 0;
}

double kelvinToFahrenheit (double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}