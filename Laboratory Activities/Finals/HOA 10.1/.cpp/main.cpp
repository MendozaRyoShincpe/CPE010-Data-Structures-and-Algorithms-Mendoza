#include <iostream>
#include "graph.h"

int main() {
    // Graph edges: {start_vertex, end_vertex, weight}
    graphEdge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    // Number of vertices
    int N = 6;

    // Calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);

    // Create the directed graph
    DiaGraph diagraph(edges, n, N);

    // Display adjacency list
    std::cout << "Graph adjacency list" << std::endl;
    std::cout << "(start_vertex, end_vertex, weight):" << std::endl;

    for (int i = 0; i < N; i++) {
        display_AdjList(diagraph.head[i], i);
    }

    return 0;
}