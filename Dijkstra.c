//Dijkstra Algorithm.
#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10 // Maximum number of nodes in the graph

// Function to find the node with the minimum distance that has not been visited
int findMinDistance(int dist[], int visited[], int n) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's Algorithm to find the shortest path from source
void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src) {
    int dist[MAX_NODES];     // Array to store the shortest distance from source
    int visited[MAX_NODES];   // Array to track visited nodes

    // Initialize distance array and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;     // Set all distances to infinity initially
        visited[i] = 0;        // No nodes are visited initially
    }

    dist[src] = 0; // The distance from the source to itself is always 0

    // Loop over all nodes
    for (int count = 0; count < n - 1; count++) {
        // Get the node with the minimum distance that hasn't been visited yet
        int u = findMinDistance(dist, visited, n);
        
        // Mark this node as visited
        visited[u] = 1;

        // Update the distance of the adjacent nodes of the selected node
        for (int v = 0; v < n; v++) {
            // If the edge exists and the node is not visited
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the resulting distances
    printf("Node\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", i);
        if (dist[i] == INT_MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    int n, src;

    // Input number of nodes in the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize the adjacency matrix for the graph
    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the adjacency matrix (enter 0 for no direct edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the source node
    printf("Enter the source node: ");
    scanf("%d", &src);

    // Call Dijkstra's algorithm
    dijkstra(graph, n, src);

    return 0;
}
