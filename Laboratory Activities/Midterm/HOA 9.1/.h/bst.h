#ifndef BST_H
#define BST_H

// BinarySearchTree is a template class
template <typename T>
class BinarySearchTree
{
private:
    // Stores the value of the current node
    T key;

    // Pointer to the left child
    BinarySearchTree<T> *leftChild;

    // Pointer to the right child
    BinarySearchTree<T> *rightChild;

public:
    // Constructor
    BinarySearchTree(T rootnode);

    // Insert a new value into the BST
    void insert(T newNode);

    // Access the left and right children
    BinarySearchTree<T> *getLeftChild();
    BinarySearchTree<T> *getRightChild();

    // Get the value of the current node
    T getRootVal();

    // Traversal functions
    void inOrder();
    void preOrder();
    void postOrder();
};


// Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T rootnode)
{
    // Assign the given value to the node
    key = rootnode;

    // Set the children to nullptr
    leftChild = nullptr;
    rightChild = nullptr;
}


// Insert a value into the Binary Search Tree
template <typename T>
void BinarySearchTree<T>::insert(T newNode)
{
    // Smaller values go to the left
    if (newNode < key)
    {
        if (leftChild == nullptr)
        {
            leftChild = new BinarySearchTree<T>(newNode);
        }
        else
        {
            leftChild->insert(newNode);
        }
    }

    // Larger values go to the right
    else if (newNode > key)
    {
        if (rightChild == nullptr)
        {
            rightChild = new BinarySearchTree<T>(newNode);
        }
        else
        {
            rightChild->insert(newNode);
        }
    }
}


// Get the left child
template <typename T>
BinarySearchTree<T> *BinarySearchTree<T>::getLeftChild()
{
    return leftChild;
}


// Get the right child
template <typename T>
BinarySearchTree<T> *BinarySearchTree<T>::getRightChild()
{
    return rightChild;
}


// Get the value of the current node
template <typename T>
T BinarySearchTree<T>::getRootVal()
{
    return key;
}


// In-order traversal
template <typename T>
void BinarySearchTree<T>::inOrder()
{
    if (leftChild != nullptr)
    {
        leftChild->inOrder();
    }

    std::cout << key << " ";

    if (rightChild != nullptr)
    {
        rightChild->inOrder();
    }
}


// Pre-order traversal
template <typename T>
void BinarySearchTree<T>::preOrder()
{
    std::cout << key << " ";

    if (leftChild != nullptr)
    {
        leftChild->preOrder();
    }

    if (rightChild != nullptr)
    {
        rightChild->preOrder();
    }
}


// Post-order traversal
template <typename T>
void BinarySearchTree<T>::postOrder()
{
    if (leftChild != nullptr)
    {
        leftChild->postOrder();
    }

    if (rightChild != nullptr)
    {
        rightChild->postOrder();
    }

    std::cout << key << " ";
}

#endif