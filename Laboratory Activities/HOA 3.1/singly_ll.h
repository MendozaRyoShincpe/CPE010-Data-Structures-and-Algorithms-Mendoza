#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};


// Traverse the list
void traverse(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;
}


// Insert at the start
void insertStart(Node*& head, char value) {

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}


// Insert after a specific node
void insertAfter(Node* previous, char value) {

    if (previous == nullptr)
        return;

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = previous->next;

    previous->next = newNode;
}


// Delete a node
void deleteNode(Node*& head, char value) {

    Node* current = head;
    Node* previous = nullptr;


    // If deleting the first node
    if (current != nullptr && current->data == value) {

        head = current->next;
        delete current;
        return;
    }


    // Search for the node
    while (current != nullptr && current->data != value) {

        previous = current;
        current = current->next;
    }


    // Delete if found
    if (current != nullptr) {

        previous->next = current->next;
        delete current;
    }
}


#endif