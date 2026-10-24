#include <iostream>
#include "bst.h"

int main()
{
    // Create the root node with the value 2
    BinarySearchTree<int> *root =
        new BinarySearchTree<int>(2);

    // Insert the remaining values
    root->insert(3);
    root->insert(9);
    root->insert(18);
    root->insert(0);
    root->insert(1);
    root->insert(4);
    root->insert(5);

    // Display the root
    std::cout << "Root: "
              << root->getRootVal() << std::endl;

    std::cout << "In-order Traversal: ";
    root->inOrder();

    std::cout << "\nPre-order Traversal: ";
    root->preOrder();

    std::cout << "\nPost-order Traversal: ";
    root->postOrder();

    std::cout << std::endl;

    return 0;
}