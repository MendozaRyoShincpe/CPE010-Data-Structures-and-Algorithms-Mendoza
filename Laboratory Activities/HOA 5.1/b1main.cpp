#include <iostream>
#include "queuell.h"

int main()
{
    qNode<char> *front = nullptr;
    qNode<char> *back = nullptr;

    enqueue(&front, &back, 'R');
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;

    enqueue(&front, &back, 'Y');
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;

    enqueue(&front, &back, 'O');
    std::cout << "Front: " << front->data << " Back: " << back->data << std::endl;

    std::cout << "\nDequeue (R)" << std::endl;
    dequeue(&front, &back);

    std::cout << "Front: " << front->data
              << " Back: " << back->data << std::endl;

    std::cout << "\nDisplay all: " << std::endl;
    display(front);

    std::cout << "Front Element: " << frontFind(front) << std::endl;

    return 0;
}