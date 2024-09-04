#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} DisjointSet;

Edge edges[MAX_EDGES];
DisjointSet sets[MAX_VERTICES];
int numVertices, numEdges;

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void initializeDisjointSets() {
    for (int i = 0; i < numVertices; i++) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
}

int find(int i) {
    if (sets[i].parent != i) {
        sets[i].parent = find(sets[i].parent);
    }
    return sets[i].parent;
}

void unionSets(int i, int j) {
    int rootI = find(i);
    int rootJ = find(j);

    if (rootI != rootJ) {
        if (sets[rootI].rank < sets[rootJ].rank) {
            sets[rootI].parent = rootJ;
        } else if (sets[rootI].rank > sets[rootJ].rank) {
            sets[rootJ].parent = rootI;
        } else {
            sets[rootJ].parent = rootI;
            sets[rootI].rank++;
        }
    }
}

void kruskal() {
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    int mstWeight = 0;
    printf("Arestas da Árvore Geradora Mínima:\n");

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d: %d\n", u, v, edges[i].weight);
            unionSets(u, v);
            mstWeight += edges[i].weight;
        }
    }
    printf("Peso total da Árvore Geradora Mínima: %d\n", mstWeight);
}

int main() {
    printf("Digite o número de vértices e arestas: ");
    scanf("%d %d", &numVertices, &numEdges);

    printf("Digite as arestas (u, v, peso):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    initializeDisjointSets();
    kruskal();

    return 0;
}
