#include <iostream>
#include "singly_ll.h"

using namespace std;

int main() {

    // Create the initial list: C -> P -> E -> 1 -> 0 -> 1
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *last = new Node;

    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '1';
    fourth->next = fifth;

    fifth->data = '0';
    fifth->next = last;

    last->data = '1';
    last->next = nullptr;

    // a. Traverse the list
    cout << "(a) Traverse the original list:" << endl;
    traverse(head);
    cout << endl;

    // b. Insert G at the start
    cout << "(b) Insert G at the start:" << endl;
    insertStart(head, 'G');
    traverse(head);
    cout << endl;

    // c. Insert E after P
    cout << "(c) Insert E after P:" << endl;

    Node *current = head;
    while (current != nullptr && current->data != 'P')
        current = current->next;

    insertAfter(current, 'E');
    traverse(head);
    cout << endl;

    // d. Delete C
    cout << "(d) Delete C:" << endl;
    deleteNode(head, 'C');
    traverse(head);
    cout << endl;

    // e. Delete P
    cout << "(e) Delete P:" << endl;
    deleteNode(head, 'P');
    traverse(head);
    cout << endl;

    // f. Display final list
    cout << "(f) Final list:" << endl;
    traverse(head);

    return 0;
}