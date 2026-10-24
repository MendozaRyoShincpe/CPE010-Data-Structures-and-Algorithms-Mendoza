#include <iostream>
#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qNode
{
public:
    T data;
    qNode<T> *next;
};

// Create a new node
template <typename T>
qNode<T> *new_node(T newData)
{
    qNode<T> *newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// Enqueue
template <typename T>
void enqueue(qNode<T> **frontPtr, qNode<T> **backPtr, T newData)
{
    // Create new node
    qNode<T> *newNode = new_node(newData);

    // Queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr)
    {
        *frontPtr = newNode;
        *backPtr = newNode;
        return;
    }

    // Queue is not empty
    (*backPtr)->next = newNode;
    *backPtr = newNode;
}

// Dequeue
template <typename T>
void dequeue(qNode<T> **frontPtr, qNode<T> **backPtr)
{
    // Queue is empty
    if (*frontPtr == nullptr)
    {
        return;
    }

    // Temporary node
    qNode<T> *deleteNode = *frontPtr;

    // Only one node
    if ((*frontPtr)->next == nullptr)
    {
        *frontPtr = nullptr;
        *backPtr = nullptr;
        delete deleteNode;
        return;
    }

    // More than one node
    *frontPtr = (*frontPtr)->next;
    delete deleteNode;
}

// display all the elements
template <typename T>
void display(qNode<T> *frontPtr)
{
    qNode<T> *temp = frontPtr;

    if (temp == nullptr)
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    while (temp != nullptr)
    {
        std::cout << temp->data << " \n";
        temp = temp->next;
    }
}

// return the front variable
template <typename T>
T frontFind (qNode<T> *frontPtr) {
    return frontPtr->data;
}

#endif
