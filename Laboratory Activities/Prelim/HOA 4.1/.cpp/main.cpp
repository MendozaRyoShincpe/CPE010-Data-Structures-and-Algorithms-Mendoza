#include <iostream>
#include "stackList.h"

int main()
{

    std::cout << "--- PUSHING 'C' 'P' 'E' ONTO THE STACK --- \n";

    // push
    push('C');
    push('P');
    push('E');

    // display the current top
    Top<char>(); // top should be 'E'

    std::cout << "\n -------Popping all the elements ---------\n";

    while (!isEmpty<char>())
    {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n ------Testing the Underflow ------\n";
    pop<char>();

    std::cout << "\n------Display all-------\n";
    display<char>();

    return 0;
}
