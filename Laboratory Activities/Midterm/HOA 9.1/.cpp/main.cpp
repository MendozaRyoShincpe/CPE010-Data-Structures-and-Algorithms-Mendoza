#include <iostream>
#include "generalTree.h"

int main()
{
    // Create the root node with the value 'A'
    GeneralTree<char> *root = new GeneralTree<char>('A');

    // Create the children of root A
    root->insertChild('B');
    root->insertChild('C');
    root->insertChild('D');
    root->insertChild('E');
    root->insertChild('F');
    root->insertChild('G');

    // Access node D and create its child H
    root->getChild(2)->insertChild('H');

    // Access node E and create its children I and J
    root->getChild(3)->insertChild('I');
    root->getChild(3)->insertChild('J');

    // Access node J and create its children P and Q
    root->getChild(3)->getChild(1)->insertChild('P');
    root->getChild(3)->getChild(1)->insertChild('Q');

    // Access node F and create its children K, L, and M
    root->getChild(4)->insertChild('K');
    root->getChild(4)->insertChild('L');
    root->getChild(4)->insertChild('M');

    // Access node G and create its child N
    root->getChild(5)->insertChild('N');

    // Display the value of the root node
    std::cout << "Root: "
              << root->getRootVal() << std::endl;

    // Display the first child of A
    std::cout << "First Child of A: "
              << root->getChild(0)->getRootVal() << std::endl;

    // Display the third child of A
    std::cout << "Third Child of A: "
              << root->getChild(2)->getRootVal() << std::endl;

    // Display the child of D
    std::cout << "Child of D: "
              << root->getChild(2)->getChild(0)->getRootVal()
              << std::endl;

    // Display the second child of E
    std::cout << "Second Child of E: "
              << root->getChild(3)->getChild(1)->getRootVal()
              << std::endl;

    // Display the first child of J
    std::cout << "First Child of J: "
              << root->getChild(3)
                     ->getChild(1)
                     ->getChild(0)
                     ->getRootVal()
              << std::endl;

    // Display the pre-order traversal
    std::cout << "\nPre-order: ";
    root->preOrder();

    // Display the post-order traversal
    std::cout << "\nPost-order: ";
    root->postOrder();

    // Display the in-order traversal
    std::cout << "\nIn-order: ";
    root->inOrder();

    std::cout << std::endl;

    // Search for J using pre-order
    root->findData(1, 'J');

    // Search for P using post-order
    root->findData(2, 'P');

    // Search for Z using in-order
    root->findData(3, 'Z');

    // Add O as a new child of G
    root->getChild(5)->insertChild('O');

    // Search for O using pre-order
    root->findData(1, 'O');

    return 0;
}