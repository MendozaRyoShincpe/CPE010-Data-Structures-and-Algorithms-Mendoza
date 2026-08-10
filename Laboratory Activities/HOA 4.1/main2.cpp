#include <iostream>
#include <string>
#include "Stackarray.h"

// Check if symbols match
bool isPair(char open, char close)
{
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

// Check if expression is balanced
bool checkBalance(std::string expression)
{
    // Reset stack
    top = -1;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // Opening symbols
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }

        // Closing symbols
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (isEmpty())
            {
                return false;
            }

            char temp = pop();

            if (!isPair(temp, ch))
            {
                return false;
            }
        }
    }

    return isEmpty();
}

int main()
{
    std::string expression;

    std::cout << "===============================" << std::endl;
    std::cout << "     Symbol Balance Checker" << std::endl;
    std::cout << "===============================" << std::endl;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (checkBalance(expression))
    {
        std::cout << "\nExpression is VALID." << std::endl;
    }
    else
    {
        std::cout << "\nExpression is INVALID." << std::endl;
    }

    return 0;
}