#ifndef GENERALTREE_H
#define GENERALTREE_H

// GeneralTree is a template class, so it can store different data types
template <typename T>
class GeneralTree
{
private:
    // Stores the value/data of the current node
    T key;

    // Pointer to the first child of the current node
    GeneralTree<T> *firstChild;

    // Pointer to the next sibling of the current node
    GeneralTree<T> *nextSibling;

public:
    // Constructor that creates a new node with the given value
    GeneralTree(T rootnode);

    // Function used to insert a new child node
    void insertChild(T newNode);

    // Function used to access a child node
    GeneralTree<T> *getChild(int index);

    // Functions used to get and change the value of a node
    void setRootVal(T obj);
    T getRootVal();

    // Checks whether the current node is a leaf
    bool isLeaf();
    // Functions used for tree traversals
    void preOrder();
    void postOrder();
    void inOrder();

    bool findData(int choice, T key);
};

// Constructor
template <typename T>
GeneralTree<T>::GeneralTree(T rootobj)
{
    // Assign the given value to the node
    key = rootobj;

    // Set the first child and next sibling to nullptr
    // because the new node has no children or siblings yet
    firstChild = nullptr;
    nextSibling = nullptr;
}

// Insert a new child node
template <typename T>
void GeneralTree<T>::insertChild(T newNode)
{
    // Create a new node with the given value
    GeneralTree<T> *newChild = new GeneralTree<T>(newNode);

    // Check if the current node has no children
    if (firstChild == nullptr)
    {
        // Make the new node the first child
        firstChild = newChild;
    }
    else
    {
        // Start at the first child
        GeneralTree<T> *current = firstChild;

        // Move through the sibling list
        // until the last sibling is reached
        while (current->nextSibling != nullptr)
        {
            current = current->nextSibling;
        }

        // Add the new node at the end of the sibling list
        current->nextSibling = newChild;
    }
}

// Access a child using its index
template <typename T>
GeneralTree<T> *GeneralTree<T>::getChild(int index)
{
    // Start at the first child
    GeneralTree<T> *current = firstChild;

    // Move through the siblings until the requested index
    for (int i = 0; i < index && current != nullptr; i++)
    {
        current = current->nextSibling;
    }

    // Return the child node
    return current;
}

// Change the value of the current node
template <typename T>
void GeneralTree<T>::setRootVal(T obj)
{
    key = obj;
}

// Get the value of the current node
template <typename T>
T GeneralTree<T>::getRootVal()
{
    return key;
}

// Check if the current node is a leaf node
template <typename T>
bool GeneralTree<T>::isLeaf()
{
    // A node is a leaf if it has no children
    return firstChild == nullptr;
}

template <typename T>
void GeneralTree<T>::preOrder()
{
    // Display the current node first
    std::cout << key << " ";

    // Traverse the first child
    if (firstChild != nullptr)
    {
        firstChild->preOrder();
    }

    // Traverse the next sibling
    if (nextSibling != nullptr)
    {
        nextSibling->preOrder();
    }
}

template <typename T>
void GeneralTree<T>::postOrder()
{
    // Traverse the children first
    if (firstChild != nullptr)
    {
        firstChild->postOrder();
    }

    // Display the current node
    std::cout << key << " ";

    // Traverse the next sibling
    if (nextSibling != nullptr)
    {
        nextSibling->postOrder();
    }
}

template <typename T>
void GeneralTree<T>::inOrder()
{
    // Traverse the first child first
    if (firstChild != nullptr)
    {
        firstChild->inOrder();
    }

    // Display the current node
    std::cout << key << " ";

    // Traverse the next sibling
    if (nextSibling != nullptr)
    {
        nextSibling->inOrder();
    }
}

template <typename T>
bool GeneralTree<T>::findData(int choice, T searchKey)
{
    bool found = false;

    // Pre-order
    if (choice == 1)
    {
        if (key == searchKey)
        {
            std::cout << "{" << searchKey << "} was found!" << std::endl;
            return true;
        }

        if (firstChild != nullptr)
        {
            found = firstChild->findData(choice, searchKey);

            if (found)
            {
                return true;
            }
        }

        if (nextSibling != nullptr)
        {
            found = nextSibling->findData(choice, searchKey);

            if (found)
            {
                return true;
            }
        }
    }

    // Post-order
    else if (choice == 2)
    {
        if (firstChild != nullptr)
        {
            found = firstChild->findData(choice, searchKey);

            if (found)
            {
                return true;
            }
        }

        if (nextSibling != nullptr)
        {
            found = nextSibling->findData(choice, searchKey);

            if (found)
            {
                return true;
            }
        }

        if (key == searchKey)
        {
            std::cout << "{" << searchKey << "} was found!" << std::endl;
            return true;
        }
    }

    // In-order
    else if (choice == 3)
    {
        if (firstChild != nullptr)
        {
            found = firstChild->findData(choice, searchKey);

            if (found)
            {
                return true;
            }
        }

        if (key == searchKey)
        {
            std::cout << "{" << searchKey << "} was found!" << std::endl;
            return true;
        }

        if (nextSibling != nullptr)
        {
            found = nextSibling->findData(choice, searchKey);

            if (found)
            {
                return true;
            }
        }
    }

    return false;
}

#endif