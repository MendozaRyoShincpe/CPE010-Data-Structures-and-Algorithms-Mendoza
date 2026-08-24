#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
};


// Traverse the list
void traverse(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}


// Delete a node
bool deleteNode(Node*& head, string value)
{
    Node* current = head;
    Node* previous = nullptr;

    // If deleting the first node
    if (current != nullptr && current->data == value)
    {
        head = current->next;
        delete current;
        return true;
    }

    // Search for the node
    while (current != nullptr && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    // Delete if found
    if (current != nullptr)
    {
        previous->next = current->next;
        delete current;
        return true;
    }

    return false;
}


// Search for a node
bool search(Node* head, string target)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == target)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

#endif