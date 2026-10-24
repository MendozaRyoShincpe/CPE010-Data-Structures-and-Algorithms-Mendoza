#include <iostream>
#include <vector>

struct Edge {
    char destination;
    int weight;
};

class Graph {
private:
    std::vector<std::pair<char, std::vector<Edge>>> adjacencyList;

public:
    Graph() {
        adjacencyList.push_back({'A', {}});
        adjacencyList.push_back({'B', {}});
        adjacencyList.push_back({'C', {}});
        adjacencyList.push_back({'D', {}});
    }

    void addEdge(char source, char destination, int weight) {
        for (auto& vertex : adjacencyList) {
            if (vertex.first == source) {
                vertex.second.push_back({destination, weight});
                return;
            }
        }
    }

    void displayGraph() {
        std::cout << "Directed Weighted Graph:\n\n";

        for (const auto& vertex : adjacencyList) {
            std::cout << vertex.first << " -> ";

            for (const auto& edge : vertex.second) {
                std::cout << edge.destination
                          << " (" << edge.weight << ") ";
            }

            std::cout << '\n';
        }
    }
};

int main() {
    Graph graph;

    // Add directed edges with weights
    graph.addEdge('D', 'A', 4);
    graph.addEdge('A', 'B', 3);
    graph.addEdge('A', 'C', 2);
    graph.addEdge('C', 'B', 1);

    graph.displayGraph();

    return 0;
}