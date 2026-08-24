#include <iostream>
#include "pracsingly_ll.h"

int main() {

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *last = new Node;

    head->data = "RYO";
    head->next = second;

    second->data = "JIM";
    second->next = third;

    third->data = "KHAI";
    third->next = fourth;

    fourth->data = "BEZ";
    fourth->next = last;

    last->data = "ROY";
    last->next = nullptr;

    // Search
    std::string target;
    std::cout << "Enter name to search: ";
    std::cin >> target;

    if (search(head, target))
    {
        std::cout << target << " found!" << endl;
    }
    else
    {
        std::cout << target << " not found!" << endl;
    }

    std::cout << "\nOriginal List: " << endl;
    traverse(head);

    // Delete
    std::string value;
    std::cout << "\nEnter name to delete: ";
    std::cin >> value;

    if (deleteNode(head, value))
    {
        std::cout << value << " deleted!" << endl;
    }
    else
    {
        std::cout << value << " not found!" << endl;
    }

    //Updated List
    std::cout << "\nUpdated List: " << endl;
    traverse(head);

    return 0;
}