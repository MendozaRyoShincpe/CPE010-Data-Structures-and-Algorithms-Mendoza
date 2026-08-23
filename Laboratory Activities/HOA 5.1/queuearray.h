#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>

template <typename T>
class queueArr
{
private:
    // create a pointer array
    T* q_array;

    size_t q_capacity;
    size_t q_size;

    int q_front;
    int q_back;

public:
    // prototypes to use for queueArr
    queueArr(size_t capacity);

    bool empty();
    bool full();

    size_t size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();

    ~queueArr();

    // tasks
    queueArr(const queueArr& other);
    queueArr& operator=(const queueArr& other);
};


// ============================================================
// Constructor
// ============================================================

template <typename T>
queueArr<T>::queueArr(size_t capacity)
{
    // capacity of the array
    q_capacity = capacity;

    // current size of the array
    q_size = 0;

    // initial front and back of the index
    q_front = 0;
    q_back = -1;

    // newly allocated array
    q_array = new T[q_capacity];

    std::cout << "Queue created with capacity: "
              << q_capacity << std::endl;
}


// ============================================================
// Destructor
// ============================================================

template <typename T>
queueArr<T>::~queueArr()
{
    delete[] q_array;

    std::cout << "Queue destroyed." << std::endl;
}


// ============================================================
// Empty
// ============================================================

template <typename T>
bool queueArr<T>::empty()
{
    return q_size == 0;
}


// ============================================================
// Full
// ============================================================

template <typename T>
bool queueArr<T>::full()
{
    return q_size == q_capacity;
}


// ============================================================
// Size
// ============================================================

template <typename T>
size_t queueArr<T>::size()
{
    return q_size;
}


// ============================================================
// Clear
// ============================================================

template <typename T>
void queueArr<T>::Clear()
{
    q_size = 0;
    q_front = 0;
    q_back = -1;
}


// ============================================================
// Front
// ============================================================

template <typename T>
T queueArr<T>::Front()
{
    // check if the queue is empty
    if (empty())
    {
        std::cout << "Queue is empty.\n";
        return T{};
    }

    // return the front element
    return q_array[q_front];
}


// ============================================================
// Back
// ============================================================

template <typename T>
T queueArr<T>::Back()
{
    // check if the queue is empty
    if (empty())
    {
        std::cout << "Queue is empty.\n";
        return T{};
    }

    // return the back element
    return q_array[q_back];
}


// ============================================================
// Enqueue
// ============================================================

template <typename T>
void queueArr<T>::Enqueue(T newData)
{
    // check if the queue is full
    if (full())
    {
        std::cout << "Queue is full.\n";
        return;
    }

    // move back to the next position
    q_back = (q_back + 1) % q_capacity;

    // insert the new data
    q_array[q_back] = newData;

    // increase the size
    q_size++;
}


// ============================================================
// Dequeue
// ============================================================

template <typename T>
void queueArr<T>::Dequeue()
{
    // check if the queue is empty
    if (empty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    // move front to the next position
    q_front = (q_front + 1) % q_capacity;

    // decrease the size
    q_size--;

    // reset indexes if queue becomes empty
    if (q_size == 0)
    {
        q_front = 0;
        q_back = -1;
    }
}


// ============================================================
// Copy Constructor
// ============================================================

template <typename T>
queueArr<T>::queueArr(const queueArr& other)
{
    // copy the capacity
    q_capacity = other.q_capacity;

    // copy the current size
    q_size = other.q_size;

    // copy front and back
    q_front = other.q_front;
    q_back = other.q_back;

    // create a new array
    q_array = new T[q_capacity];

    // copy all elements
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }

    std::cout << "Queue copied using copy constructor."
              << std::endl;
}


// ============================================================
// Copy Assignment Operator
// ============================================================

template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other)
{
    // prevent self-assignment
    if (this != &other) {
        // delete old array
        delete[] q_array;

        // copy capacity
        q_capacity = other.q_capacity;

        // copy size
        q_size = other.q_size;

        // copy front and back
        q_front = other.q_front;
        q_back = other.q_back;

        // create a new array
        q_array = new T[q_capacity];

        // copy elements
        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }

    return *this;
}

#endif