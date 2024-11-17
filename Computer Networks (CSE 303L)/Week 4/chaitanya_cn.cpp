// AP21110010253
#include <iostream>
#include <climits>
#include <vector>

#define V 6

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(std::vector<int>& parent, int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    std::cout << j << " ";
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    std::vector<int> parent(V, -1);

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    std::cout << "Vertex \t Distance from Source \t Path" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << i << " \t " << dist[i] << " \t " << src << " ";
        printPath(parent, i);
        std::cout << std::endl;
    }
}

int main() {
    int graph[V][V];

    std::cout << "Enter the matrix for the graph:" << std::endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cin >> graph[i][j];
        }
    }

    int sourceVertex;
    std::cout << "Enter the source : ";
    std::cin >> sourceVertex;

    dijkstra(graph, sourceVertex);

    return 0;
}