#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges based on their weight (for sorting)
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find the parent of a node (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    return subsets[i].parent;
}

// Function to perform the union of two subsets (with union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    // Union by rank
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Function to implement Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];  // Array to store the resultant MST
    int e = 0;  // Index for the resultant MST
    int i = 0;  // Index for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Step 2: Initialize subsets for each vertex
    for (i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0; // Reset index for edges
    // Step 3: Pick the smallest edge and increment the index for the next iteration
    while (e < V - 1 && i < E) {
        // Step 3.1: Get the next edge from the sorted list
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause a cycle, include it in the result
        // and take the union of these two vertices
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
        // Else discard the edge
    }

    // Step 4: Print the constructed MST
    printf("Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("\nMinimum Cost of the Spanning Tree: %d\n", minimumCost);

    free(subsets);
}

// Driver program to test the above functions
int main() {
    // Number of vertices and edges in the graph
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    // Array of edges (src, dest, weight)
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Function call to construct the MST
    kruskalMST(edges, V, E);

    return 0;
}
