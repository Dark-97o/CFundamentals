#include <stdio.h>
#include <limits.h>

#define V 5
#define E 7

typedef struct {
    int src, dest, weight;
} Edge;

void bellmanFord(Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    for (int i = 0; i < V; i++)
        printf("Vertex %d: %d\n", i, dist[i]);
}

int main() {
    Edge edges[E] = {
        {0, 1, 1}, {0, 2, 2}, {1, 2, 1}, {1, 3, -3}, 
        {2, 3, 4}, {2, 4, 3}, {3, 4, 3}
    };
    bellmanFord(edges, 0);
    return 0;
}