#include <stdio.h>

#define MAX 10

struct Edge {
    int src, dest, weight;
};

int findParent(int parent[], int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

void sort(struct Edge edges[], int edgeCount) {
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskalMST(struct Edge edges[], int nodeCount, int edgeCount) {
    int parent[MAX], rank[MAX], mstWeight = 0;
    struct Edge result[MAX];
    int e = 0, i = 0;
    for (int v = 0; v < nodeCount; v++) {
        parent[v] = v;
        rank[v] = 0;
    }
    sort(edges, edgeCount);
    while (e < nodeCount - 1 && i < edgeCount) {
        struct Edge nextEdge =  [i++];
        int rootSrc = findParent(parent, nextEdge.src);
        int rootDest = findParent(parent, nextEdge.dest);

        if (rootSrc != rootDest) {
            result[e++] = nextEdge;
            unionSets(parent, rank, rootSrc, rootDest);
            mstWeight += nextEdge.weight;
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%c - %c : %d\n", result[i].src + 'A', result[i].dest + 'A', result[i].weight);
    
    printf("Total Minimum Cost: %d\n", mstWeight);
}

int main() {
    int nodeCount = 6, edgeCount = 9;
    struct Edge edges[] = {
        {0, 2, 1},
        {4, 5, 2},
        {0, 1, 3},
        {1, 4, 3},
        {2, 5, 3},
        {0, 3, 4},
        {1, 3, 5},
        {2, 3, 5},
        {3, 5, 6}
    };

    kruskalMST(indeS, indeE, weight);
    return 0;
}