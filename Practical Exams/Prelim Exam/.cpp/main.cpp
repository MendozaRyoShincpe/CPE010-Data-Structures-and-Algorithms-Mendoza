#include <iostream>
#include <string>

#include "stackarray.h"
#include "queuell.h"

// Check Palindrome
bool checkPalindrome(std::string number)
{
    // Reset stack
    top = -1;

    // Queue pointers
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    // Store values in Stack and Queue
    for (int i = 0; i < number.length(); i++)
    {
        push(number[i]);
        enqueue(&front, &back, number[i]);
    }

    // Compare Stack and Queue
    for (int i = 0; i < number.length(); i++)
    {
        char stackValue = pop();
        char queueValue = dequeue(&front, &back);

        if (stackValue != queueValue)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string number;

    std::cout << "===============================" << std::endl;
    std::cout << "     Palindrome Number Check" << std::endl;
    std::cout << "===============================" << std::endl;

    std::cout << "Enter a number: ";
    std::cin >> number;

    // Check if input contains only digits
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            std::cout << "\nInvalid input. Please enter an integer."
                      << std::endl;
            return 0;
        }
    }

    if (checkPalindrome(number))
    {
        std::cout << "\nThe number is a PALINDROME." << std::endl;
    }
    else
    {
        std::cout << "\nThe number is NOT a PALINDROME." << std::endl;
    }

    return 0;
}