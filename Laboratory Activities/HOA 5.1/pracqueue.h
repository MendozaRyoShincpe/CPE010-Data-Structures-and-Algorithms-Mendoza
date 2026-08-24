#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

string queue[MAX];
int front = 0;
int rear = -1;
int count = 0;


// Enqueue
void enqueue(string data)
{
    if (count == MAX)
    {
        cout << "Queue is full!" << endl;
        return;
    }

    rear++;
    queue[rear] = data;
    count++;
}


// Dequeue
bool dequeue(string& data)
{
    if (count == 0)
    {
        return false;
    }

    data = queue[front];
    front++;
    count--;

    return true;
}


// Display
void display()
{
    if (count == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " -> ";
    }

    cout << "NULL" << endl;
}


// Peek / Front
bool peek(string& data)
{
    if (count == 0)
    {
        return false;
    }

    data = queue[front];
    return true;
}

#endif