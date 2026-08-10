#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>

const int MAX = 100;

// Stack array
char stack[MAX];
int top = -1;

//========================
// Push
//========================
void push(char data)
{
    if (top == MAX - 1)
    {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    top++;
    stack[top] = data;
}

//========================
// Pop
//========================
char pop()
{
    if (top == -1)
    {
        std::cout << "Stack Underflow" << std::endl;
        return '\0';
    }

    char value = stack[top];
    top--;

    return value;
}

//========================
// Is Empty
//========================
bool isEmpty()
{
    return top == -1;
}

#endif