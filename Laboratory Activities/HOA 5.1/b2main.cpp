#include <iostream>
#include "queuearray.h"

int main()
{
    // Create a queue with capacity of 6
    queueArr<int> q(6);

    std::cout << "\n===== QUEUE-ARRAY TEST =====\n\n";

    // Enqueue elements
    std::cout << "Enqueue 10, 20, 30...\n";

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    // Display size
    std::cout << "Queue size: " << q.size() << std::endl;

    // Display front and back
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;

    // Dequeue
    std::cout << "\nDequeue...\n";
    q.Dequeue();
    std::cout << "Front after Dequeue: " << q.Front() << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;

    // Enqueue
    std::cout << "\nEnqueue 40...\n";
    q.Enqueue(40);
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;

    // Check if empty
    std::cout << "\nIs queue empty? ";

    if (q.empty()) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    // Check if full
    std::cout << "Is queue full? ";

    if (q.full()) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    // Copy Constructor
    std::cout << "\n===== COPY CONSTRUCTOR =====\n";

    queueArr<int> q2(q);

    std::cout << "q2 Front: " << q2.Front() << std::endl;
    std::cout << "q2 Back: " << q2.Back() << std::endl;
    std::cout << "q2 Size: " << q2.size() << std::endl;

    // Copy Assignment Operator
    std::cout << "\n===== COPY ASSIGNMENT =====\n";
    queueArr<int> q3(6);
    q3 = q;

    std::cout << "q3 Front: " << q3.Front() << std::endl;
    std::cout << "q3 Back: " << q3.Back() << std::endl;
    std::cout << "q3 Size: " << q3.size() << std::endl;

    // Clear
    std::cout << "\n===== CLEAR =====\n";
    q.Clear();
    std::cout << "Queue size after Clear: " << q.size() << std::endl;
    std::cout << "Is queue empty? ";

    if (q.empty()) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    std::cout << "\n===== END OF PROGRAM =====\n";

    return 0;
}

#include <iostream>
#include <string>

#include "Stackarray.h"
#include "QueueLL.h"

// Check if sequence is symmetric
bool checkSymmetric(std::string sequence)
{
    // Reset stack
    top = -1;

    // Queue pointers
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    // Store every value in Stack and Queue
    for (int i = 0; i < sequence.length(); i++)
    {
        push(sequence[i]);
        enqueue(&front, &back, sequence[i]);
    }

    // Compare Stack and Queue
    for (int i = 0; i < sequence.length(); i++)
    {
        char stackValue = pop();
        char queueValue = dequeue(&front, &back);

        if (stackValue != queueValue)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string sequence;

    std::cout << "===============================" << std::endl;
    std::cout << "      Symmetric Checker" << std::endl;
    std::cout << "===============================" << std::endl;

    std::cout << "Enter sequence: ";
    std::getline(std::cin, sequence);

    if (checkSymmetric(sequence))
    {
        std::cout << "\nSequence is SYMMETRIC." << std::endl;
    }
    else
    {
        std::cout << "\nSequence is NOT SYMMETRIC." << std::endl;
    }

    return 0;
}
