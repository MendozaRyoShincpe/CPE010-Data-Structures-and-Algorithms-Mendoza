#include <iostream>
#include "queuearray.h"
using namespace std;

int main()
{
    Queue q(5);

    cout << "=== QUEUE TEST ===" << endl;

    // Test Empty()
    cout << "Is queue empty? "
         << (q.Empty() ? "Yes" : "No") << endl;

    // Test Enqueue()
    cout << "\nAdding elements: 10, 20, 30" << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    // Test Size()
    cout << "Queue size: " << q.Size() << endl;

    // Test Front()
    cout << "Front element: " << q.Front() << endl;

    // Test Back()
    cout << "Back element: " << q.Back() << endl;

    // Test Dequeue()
    cout << "\nRemoving front element..." << endl;
    q.Dequeue();

    cout << "New front: " << q.Front() << endl;
    cout << "Queue size: " << q.Size() << endl;

    // Test Copy Constructor
    cout << "\nTesting Copy Constructor..." << endl;
    Queue q2(q);

    cout << "Copied queue front: " << q2.Front() << endl;
    cout << "Copied queue back: " << q2.Back() << endl;

    // Test Assignment Operator
    cout << "\nTesting Copy Assignment Operator..." << endl;
    Queue q3;
    q3 = q;

    cout << "Assigned queue front: " << q3.Front() << endl;
    cout << "Assigned queue back: " << q3.Back() << endl;

    // Test Clear()
    cout << "\nClearing original queue..." << endl;
    q.Clear();

    cout << "Queue size: " << q.Size() << endl;
    cout << "Is queue empty? "
         << (q.Empty() ? "Yes" : "No") << endl;

    return 0;
}