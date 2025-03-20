#include <stdio.h>
#include <stdbool.h>

#define V 12 // Number of vertices

// Function to find the minimum available color
void greedyColoring(int graph[V][V]) {
    int result[V]; // Stores color assigned to vertices
    result[0] = 0; // Assign first color to first vertex
    
    for (int i = 1; i < V; i++)
        result[i] = -1; // Initialize all vertices as uncolored
    
    bool available[V]; // Keep track of available colors
    for (int i = 0; i < V; i++)
        available[i] = true;
    
    for (int u = 1; u < V; u++) {
        // Mark colors of adjacent vertices as unavailable
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && result[v] != -1)
                available[result[v]] = false;
        }
        
        // Find first available color
        int color;
        for (color = 0; color < V; color++) {
            if (available[color])
                break;
        }
        
        result[u] = color; // Assign color
        
        // Reset the availability array
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && result[v] != -1)
                available[result[v]] = true;
        }
    }
    
    // Print the result
    for (int u = 0; u < V; u++)
        printf("Vertex %d ---> Color %d\n", u + 1, result[u]);
}

int main() {
    int graph[V][V] = { {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                         {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                         {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                         {1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
                         {0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                         {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
                         {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0} };
    
    greedyColoring(graph);
    return 0;
}
