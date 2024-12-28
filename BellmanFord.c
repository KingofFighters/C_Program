#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(struct Edge edges[], int V, int E, int source) {
    // Initialize distances from source to all vertices as INFINITE
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            // If the distance to the destination vertex can be shortened
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // If we can still relax an edge, then there is a negative weight cycle
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the shortest distances from the source
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d        ", i);
        if (dist[i] == INT_MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

// Main function to drive the program
int main() {
    int V, E, source;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    // Input edges (start, end, weight)
    printf("Enter the edges (u, v, weight) for each edge:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Input source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call Bellman-Ford algorithm
    bellmanFord(edges, V, E, source);

    return 0;
}
