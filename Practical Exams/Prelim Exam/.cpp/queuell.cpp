#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode
{
public:
    T data;
    qNode<T>* next;
};


// Create New Node
template <typename T>
qNode<T>* new_node(T newData)
{
    qNode<T>* newNode = new qNode<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    return newNode;
}


// Enqueue
template <typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData)
{
    qNode<T>* newNode = new_node(newData);

    if (*frontPtr == nullptr && *backPtr == nullptr)
    {
        *frontPtr = newNode;
        *backPtr = newNode;
        return;
    }

    (*backPtr)->next = newNode;
    *backPtr = newNode;
}


// Dequeue
template <typename T>
T dequeue(qNode<T>** frontPtr, qNode<T>** backPtr)
{
    if (*frontPtr == nullptr)
    {
        return '\0';
    }

    qNode<T>* deleteNode = *frontPtr;

    T value = deleteNode->data;

    if ((*frontPtr)->next == nullptr)
    {
        *frontPtr = nullptr;
        *backPtr = nullptr;
    }
    else
    {
        *frontPtr = (*frontPtr)->next;
    }

    delete deleteNode;

    return value;
}

#endif