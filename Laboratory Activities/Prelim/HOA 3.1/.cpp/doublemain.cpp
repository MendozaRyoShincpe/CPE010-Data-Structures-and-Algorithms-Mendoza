#include <iostream>
#include "double_LL.h"

int main() {

    // Create the list: C -> P -> E
    doubleList<char>* head = new_node('C');
    doubleList<char>* second = new_node('P');
    doubleList<char>* third = new_node('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    // Initial Traversal
    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    // Insert at Head
    std::cout << "\nInsert at Head:" << std::endl;
    dllInsertHead('G', &head);
    dllTraverse(head);

    // Insert at End
    std::cout << "\nInsert at End:" << std::endl;
    dllInsertEnd('1', head);
    dllTraverse(head);

    // General Insertion
    std::cout << "\nGeneral Insertion (Insert 6 after P):" << std::endl;
    dllGeneralInsertion(second, '6');
    dllTraverse(head);

    // Delete
    std::cout << "\nDelete P:" << std::endl;
    dllDelete('P', &head);
    dllTraverse(head);

    return 0;
}