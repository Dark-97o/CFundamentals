#include <stdio.h>
#include <limits.h>

#define V 5

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 8, INT_MAX, -4},
        {INT_MAX, 0, INT_MAX, 1, 7},
        {INT_MAX, 4, 0, INT_MAX, INT_MAX},
        {2, INT_MAX, -5, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 6, 0}
    };
    floydWarshall(graph);
    return 0;
}
