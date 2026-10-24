#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <cstring>


// ============================================================
// QUEUE ARRAY CLASS
// ============================================================

template <typename T>
class queueArr
{
private:
    T* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    queueArr(int capacity);
    ~queueArr();

    bool empty();
    bool full();
    int size();

    T Front();

    void Enqueue(T newData);
    void Dequeue();
};


// Constructor
template <typename T>
queueArr<T>::queueArr(int capacity)
{
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;

    q_array = new T[q_capacity];
}


// Destructor
template <typename T>
queueArr<T>::~queueArr()
{
    delete[] q_array;
}


// Check if queue is empty
template <typename T>
bool queueArr<T>::empty()
{
    return q_size == 0;
}


// Check if queue is full
template <typename T>
bool queueArr<T>::full()
{
    return q_size == q_capacity;
}


// Get queue size
template <typename T>
int queueArr<T>::size()
{
    return q_size;
}


// Get front element
template <typename T>
T queueArr<T>::Front()
{
    if (empty())
    {
        return T{};
    }

    return q_array[q_front];
}


// Add element to queue
template <typename T>
void queueArr<T>::Enqueue(T newData)
{
    if (full())
    {
        std::cout << "Queue is full." << std::endl;
        return;
    }

    q_back = (q_back + 1) % q_capacity;

    q_array[q_back] = newData;

    q_size++;
}


// Remove element from queue
template <typename T>
void queueArr<T>::Dequeue()
{
    if (empty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    q_front = (q_front + 1) % q_capacity;

    q_size--;

    if (q_size == 0)
    {
        q_front = 0;
        q_back = -1;
    }
}


// ============================================================
// JOB CLASS
// ============================================================

class Job
{
private:
    int id;
    char user[50];
    int pages;

public:
    // Default values allow the queue to create an empty array
    Job(int jobID = 0, const char* userName = "", int numberOfPages = 0) {
        id = jobID;

        std::strncpy(user, userName, 49);
        user[49] = '\0'; // can be store up to 49 char of letters to the names

        pages = numberOfPages;
    }

    void display()
    {
        std::cout << "Job ID: " << id << std::endl;
        std::cout << "User: " << user << std::endl;
        std::cout << "Pages: " << pages << std::endl;
    }
};


// ============================================================
// PRINTER CLASS
// ============================================================

class Printer
{
private:
    queueArr<Job> jobs; //objects

public:
    // Constructor
    Printer(int capacity) : jobs(capacity)
    {
    }

    // Add a new print job
void AddJob(Job newJob)
    {
        if (jobs.full())
        {
            std::cout << "Printer queue is full." << std::endl;
            return;
        }

        jobs.Enqueue(newJob);
        std::cout << "Job added to printer." << std::endl;
    }

    // Process one job
void ProcessJob()
    {
        if (jobs.empty())
        {
            std::cout << "No jobs to print."
                      << std::endl;
            return;
        }

        Job currentJob = jobs.Front();

        std::cout << "\nPrinting job..." << std::endl;

        currentJob.display();

        std::cout << "Job completed."
                  << std::endl;

        jobs.Dequeue();
    }

    // Process all jobs
void ProcessAll()
    {
        while (!jobs.empty())
        {
            ProcessJob();
        }
    }
};

#endif