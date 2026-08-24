#include <iostream>
#include "pracstackarr.h"

int main()
{
    int value;

    // Input 5 numbers
    cout << "Enter 5 numbers: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        push(value);
    }


    cout << "Stack:" << endl;
    display();


    // Pop 2 numbers

    if (pop(value))
    {
        cout << "Popped: " << value << endl;
    }

    if (pop(value))
    {
        cout << "Popped: " << value << endl;
    }


    // Display updated stack
    cout << "\nUpdated Stack:" << endl;
    display();


    // Show top
    if (peak(value))
    {
        cout << "\nTop: " << value << endl;
    }


    return 0;
}