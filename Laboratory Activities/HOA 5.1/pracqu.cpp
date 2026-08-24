#include <iostream>
#include <string>
#include "pracqueue.h"

int main()
{
    string name;

    // Input 5 customers
    cout << "Enter 5 customer names:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> name;
        enqueue(name);
    }


    // Display queue
    cout << "\nQueue:" << endl;
    display();


    // Dequeue 2 customers
    cout << "\nDequeue 2 customers:" << endl;

    if (dequeue(name))
    {
        cout << "Dequeued: " << name << endl;
    }

    if (dequeue(name))
    {
        cout << "Dequeued: " << name << endl;
    }


    // Display updated queue
    cout << "\nUpdated Queue:" << endl;
    display();


    // Show front customer
    if (peek(name))
    {
        cout << "\nFront: " << name << endl;
    }


    return 0;
}