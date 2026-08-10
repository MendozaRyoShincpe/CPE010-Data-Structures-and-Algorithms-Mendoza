#include <iostream>

class Node
{
public:
    char data;
    Node *next;
};

int main()
{
    // step 1: Create the node pointing to null
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;

    // step 2: 
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;
    last = new Node;


    // step 2
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '0';
    fourth->next = fifth;

    fifth->data = '1';
    fifth->next = last;

    last->data = '0';
    last->next = nullptr;

    //[C] → [P] → [E] → [0] → [1] → [0] → NULL
}
