#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

// class node that contains data and the next pointer
template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
};

// global pointer for the top of the stack
template <typename T>
Node<T>* head = nullptr;


//========================
// push operation
//========================
template <typename T>
void push(T newData)
{
    // create a new node
    Node<T>* newNode = new Node<T>;

    // store data
    newNode->data = newData;

    // point to current top
    newNode->next = head<T>;

    // update top
    head<T> = newNode;
}


//========================
// pop operation
//========================
template <typename T>
T pop()
{
    // check if stack is empty
    if (head<T> == nullptr)
    {
        std::cout << "Stack underflow" << std::endl;
        return T();
    }

    // store current top node
    Node<T>* temp = head<T>;

    // save the data
    T tempVal = temp->data;

    // move top to next node
    head<T> = head<T>->next;

    // delete removed node
    delete temp;

    // return removed value
    return tempVal;
}


//========================
// display top operation
//========================
template <typename T>
void Top()
{
    if (head<T> == nullptr)
    {
        std::cout << "Stack underflow" << std::endl;
        return;
    }

    std::cout << "Top of stack: " << head<T>->data << std::endl;
}


//========================
// check if empty
//========================
template <typename T>
bool isEmpty()
{
    return head<T> == nullptr;
}

//========================
// display all stack elements
//========================
template <typename T>
void display()
{
    if (head<T> == nullptr)
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    Node<T>* current = head<T>;

    std::cout << "Stack elements: ";

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

#include <string>

//========================
// check if symbols match
//========================
bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

//========================
// check if expression is balanced
//========================
bool isBalanced(const std::string& expression)
{
    // clear the stack
    while (!isEmpty<char>())
    {
        pop<char>();
    }

    for (char ch : expression)
    {
        // opening symbols
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push<char>(ch);
        }

        // closing symbols
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty<char>())
            {
                return false;
            }

            char top = pop<char>();

            if (!isMatching(top, ch))
            {
                return false;
            }
        }
    }

    return isEmpty<char>();
}

#endif