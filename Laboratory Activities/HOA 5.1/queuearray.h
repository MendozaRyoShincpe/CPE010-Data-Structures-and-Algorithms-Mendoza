#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>
using namespace std;

class Queue
{
private:
    int* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    // Constructor
    Queue(int capacity = 10)
    {
        q_capacity = capacity;
        q_array = new int[q_capacity];
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Checks if queue is empty
    bool Empty() const
    {
        return q_size == 0;
    }

    // Returns the number of elements
    int Size() const
    {
        return q_size;
    }

    // Clears the queue
    void Clear()
    {
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Returns the front element
    int Front() const
    {
        if (Empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return q_array[q_front];
    }

    // Returns the back element
    int Back() const
    {
        if (Empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return q_array[q_back];
    }

    // Adds an element to the queue
    void Enqueue(int value)
    {
        if (q_size == q_capacity)
        {
            cout << "Queue is full." << endl;
            return;
        }

        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = value;
        q_size++;
    }

    // Removes the front element
    void Dequeue()
    {
        if (Empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }

    // Copy Constructor
    Queue(const Queue& other)
    {
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new int[q_capacity];

        for (int i = 0; i < q_capacity; i++)
        {
            q_array[i] = other.q_array[i];
        }
    }

    // Copy Assignment Operator
    Queue& operator=(const Queue& other)
    {
        if (this != &other)
        {
            delete[] q_array;

            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;

            q_array = new int[q_capacity];

            for (int i = 0; i < q_capacity; i++)
            {
                q_array[i] = other.q_array[i];
            }
        }

        return *this;
    }

    // Destructor
    ~Queue()
    {
        delete[] q_array;
    }
};

#endif