#include <stdio.h>
#include <limits.h>

#define V 7

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Distance %d\n", i + 1, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 9, 0, 0, 0, 0, 10},
        {9, 0, 8, 0, 0, 12, 0},
        {0, 8, 0, 24, 0, 0, 0},
        {0, 0, 24, 0, 11, 0, 15},
        {0, 0, 0, 11, 0, 14, 0},
        {0, 12, 0, 0, 14, 0, 19},
        {10, 0, 0, 15, 0, 19, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
