#include <iostream>
using namespace std;

// Create the node class
class Node {
public:
    char data;
    Node* next;
};

int main() {
    
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

    head->data = 'P';
    head->next = second;

    second->data = 'E';
    second->next = third;

    third->data = '0';
    third->next = fourth;

    fourth->data = '1';
    fourth->next = fifth;

    fifth->data = '0';
    fifth->next = nullptr;
    
    /* Insertion at the head
    // Step 1: Allocate memory for the new node
    Node *newNode = new Node;

    // Step 2: Put data into the new node
    newNode->data = 'C';

    // Step 3: Point the new node to the previous head
    newNode->next = head;

    // Step 4: Reset head to the new node
    head = newNode;
    */

    /* Insertion at any part
    // Create the new node
    Node *newNode = new Node;
    newNode->data = 'X';

    // Traverse to the node after which you want to insert
    Node *current = head;
    while (current->data != 'E') {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
    */

    /*/ Insert at the end
     // Step 1: Create the new node
    Node *newNode = new Node;
    newNode->data = '1';
    newNode->next = nullptr;

    // Step 2: Traverse to the last node
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Step 3: Link the last node to the new node
    current->next = newNode;
    */

    // Delete the node containing 'E'
    Node *current = head;
    Node *previous = nullptr;

    while (current != nullptr && current->data != 'E') {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        previous->next = current->next;
        delete current;
    }

    // Display the linked list (Transversal)
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL";

    return 0;
}