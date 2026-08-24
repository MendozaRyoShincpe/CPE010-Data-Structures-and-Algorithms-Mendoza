#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 5;

int stack[MAX];
int top = -1;


// Push
void push(int data)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow!" << endl;
        return;
    }

    top++;
    stack[top] = data;
}


// Pop
bool pop(int& data)
{
    if (top == -1)
    {
        return false;
    }

    data = stack[top];
    top--;

    return true;
}


// Display
void display()
{
    if (top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}


// Top
bool peak(int& data)
{
    if (top == -1)
    {
        return false;
    }

    data = stack[top];
    return true;
}

#endif