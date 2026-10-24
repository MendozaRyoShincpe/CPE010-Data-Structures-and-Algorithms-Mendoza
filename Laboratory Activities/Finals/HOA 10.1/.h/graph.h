#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

// Stores adjacency list items
struct adjNode {
    int val;
    int cost;
    adjNode* next;
};

// Structure to store edges
struct graphEdge {
    int start_ver;
    int end_ver;
    int weight;
};

class DiaGraph {
private:
    // Insert new node into adjacency list
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;

        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;

        return newNode;
    }

    int N; // Number of nodes in the graph

public:
    adjNode** head; // Adjacency list

    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;

        // Allocate array of adjacency list pointers
        head = new adjNode*[N];

        // Initialize all heads to nullptr
        for (int i = 0; i < N; ++i) {
            head[i] = nullptr;
        }

        // Add all directed edges
        for (int i = 0; i < n; ++i) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

            // Insert new node at the beginning
            adjNode* newNode =
                getAdjListNode(end_ver, weight, head[start_ver]);

            head[start_ver] = newNode;
        }
    }

    // Destructor
    ~DiaGraph() {
        for (int i = 0; i < N; ++i) {
            adjNode* current = head[i];

            while (current != nullptr) {
                adjNode* next = current->next;
                delete current;
                current = next;
            }
        }

        delete[] head;
    }
};

// Display adjacency list of a vertex
void display_AdjList(adjNode* ptr, int i) {
    while (ptr != nullptr) {
        std::cout << "("
                  << i << ", "
                  << ptr->val << ", "
                  << ptr->cost
                  << ") ";

        ptr = ptr->next;
    }

    std::cout << std::endl;
}

#endif