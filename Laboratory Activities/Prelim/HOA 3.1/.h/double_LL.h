#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next;
    doubleList<T>* prev;
};

//====================
// Create a Node
//====================
template <typename T>
doubleList<T>* new_node(T newData) {

    doubleList<T>* newNode = new doubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

//====================
// Traversal
//====================
template <typename T>
void dllTraverse(doubleList<T>* currentNode) {

    doubleList<T>* tail = nullptr;

    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    std::cout << "Reverse Traversal: ";

    while (tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

//====================
// Insert at Head
//====================
template <typename T>
void dllInsertHead(T newData, doubleList<T>** head) {

    doubleList<T>* newNode = new_node(newData);

    newNode->next = *head;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

//====================
// Insert at End
//====================
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* head) {

    if (head == nullptr)
        return;

    doubleList<T>* newNode = new_node(newData);

    doubleList<T>* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

//====================
// General Insertion
//====================
template <typename T>
void dllGeneralInsertion(doubleList<T>* prevNode, T newData) {
    
    //Check if the previous node exist
    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }
        
    
    //Create a new node
    doubleList<T>* newNode = new_node(newData);

    // Connect the new node
    // New node points to the  node after the prevNode
    newNode->next = prevNode->next;

    // newNode previous must be pointed to the prevNode
    newNode->prev = prevNode;
    
    //Check if there is a node after prevNode 
    // make it point back to the newNode
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    
    // prevNode will be pointed to the newNode
    prevNode->next = newNode;
}

//====================
// Delete
//====================
template <typename T>
void dllDelete(T findData, doubleList<T>** head) {

    doubleList<T>* current = *head;

    //Search for the node
    while (current != nullptr && current->data != findData) {
        current = current->next;
    }
    
    // If value not found
    if (current == nullptr) {
        return;
    }
   
    // If deleting the head
    if (current == *head) {
        *head = current->next;
    }

    // Update the previous node 
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    
    //Update next node 
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

#endif