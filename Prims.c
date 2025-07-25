#include <stdio.h>
#include <limits.h>

#define V 5 

// Find the vertex with the minimum key value not yet included in MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[V][V]) {
    int parent[V];  // Stores the constructed MST
    int key[V];     // Key values used to pick minimum weight edge
    int mstSet[V];  // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;       // Make key 0 so that this vertex is picked first
    parent[0] = -1;   // First node is always root of MST

    // Construct MST with V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // Pick minimum key vertex not yet included
        mstSet[u] = 1;  // Add to MST set

        // Update key and parent index of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    
    printMST(parent, graph);
}


int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
