#include <stdio.h>
#include <limits.h>

#define V 6  // Number of vertices (You can change this as needed)

// Find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Print the shortest path distances from source
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Shortest distance from src to i
    int visited[V];  // visited[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as infinite and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0; // Distance from source to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); // Pick the minimum distance vertex
        visited[u] = 1;

        // Update dist[v] only if not visited and there's an edge u-v
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the result
    printSolution(dist);
}

// Example usage
int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 10},
        {4, 0, 3, 0, 0, 0},
        {0, 3, 0, 2, 0, 0},
        {0, 0, 2, 0, 1, 0},
        {0, 0, 0, 1, 0, 5},
        {10, 0, 0, 0, 5, 0}
    };

    dijkstra(graph, 0); // Source vertex = 0

    return 0;
}
