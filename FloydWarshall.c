#include <stdio.h>
#include <limits.h>

#define INF INT_MAX // Define a large value as infinity

// Function to print the solution matrix
void printSolution(int dist[][10], int V) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall algorithm to find shortest paths
void floydWarshall(int graph[][10], int V) {
    int dist[V][V];

    // Initialize the solution matrix the same as the input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j) {
                dist[i][j] = INF; // No edge between i and j
            } else {
                dist[i][j] = graph[i][j]; // Direct edge distance
            }
        }
    }

    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the solution matrix
    printSolution(dist, V);
}

int main() {
    int V, E;

    // Read number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int graph[V][V];

    // Initialize the graph with 0 (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                graph[i][j] = 0; // Distance from a vertex to itself is 0
            else
                graph[i][j] = 0;
        }
    }

    // Read all edges
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
    }

    // Call Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
