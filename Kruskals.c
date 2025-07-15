#include <stdio.h>

#define MAX 100
#define INF 999

int parent[MAX];

// Find the root of a set
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Union of two sets
int union_set(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n = 4; 

    
    int cost[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 10, 6, 0},
        {0, 10, 0, 5, 15},
        {0, 6, 5, 0, 4},
        {0, 0, 15, 4, 0}
    };

    int ne = 1, total_cost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");

    while (ne < n) {
        int min = INF, a = -1, b = -1, u, v;

        // Find the edge with minimum cost
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min && i != j) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (union_set(u, v)) {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            total_cost += min;
        }

        cost[a][b] = cost[b][a] = INF; // Mark edge as used
    }

    printf("Total cost of MST = %d\n", total_cost);
    return 0;
}
