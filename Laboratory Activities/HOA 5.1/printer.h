#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
using namespace std;

// Task 1: Job class
class Job {
public:
    int id;
    string user;
    int pages;

    Job(int i, string u, int p) {
        id = i;
        user = u;
        pages = p;
    }
};

// Node for the linked list
class Node {
public:
    Job* job;
    Node* next;

    Node(Job* j) {
        job = j;
        next = nullptr;
    }
};

// Task 2 and 3: Printer class
class Printer {
private:
    Node* front;
    Node* rear;

public:
    Printer() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a job
    void addJob(Job* job) {
        Node* newNode = new Node(job);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Job " << job->id << " added by "
             << job->user << " (" << job->pages
             << " pages)" << endl;
    }

    // Process jobs
    void processJobs() {
        cout << "\nProcessing Jobs:" << endl;

        while (front != nullptr) {
            cout << "Printing Job " << front->job->id
                 << " - " << front->job->user
                 << " (" << front->job->pages
                 << " pages)" << endl;

            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

#endif