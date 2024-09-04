#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Estrutura para representar um vértice
struct Vertex {
  int id;
  int distance;
  bool visited;
};

// Estrutura para representar uma aresta
struct Edge {
  int source;
  int destination;
  int weight;
};

// Estrutura para representar o grafo
struct Graph {
  int numVertices;
  struct Vertex vertices[MAX_VERTICES];
  struct Edge edges[MAX_VERTICES * MAX_VERTICES];
  int numEdges;
};

// Função para inicializar o grafo
void initializeGraph(struct Graph *graph, int numVertices) {
  graph->numVertices = numVertices;
  graph->numEdges = 0;

  // Inicializa os vértices
  for (int i = 0; i < numVertices; i++) {
    graph->vertices[i].id = i;
    graph->vertices[i].distance = INT_MAX;
    graph->vertices[i].visited = false;
  }
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph *graph, int source, int destination, int weight) {
  graph->edges[graph->numEdges].source = source;
  graph->edges[graph->numEdges].destination = destination;
  graph->edges[graph->numEdges].weight = weight;
  graph->numEdges++;
}

// Função para encontrar o vértice não visitado com a menor distância
int findMinDistanceVertex(struct Graph *graph) {
  int minDistance = INT_MAX;
  int minVertex = -1;

  for (int i = 0; i < graph->numVertices; i++) {
    if (!graph->vertices[i].visited && graph->vertices[i].distance < minDistance) {
      minDistance = graph->vertices[i].distance;
      minVertex = i;
    }
  }

  return minVertex;
}

// Função para implementar o algoritmo de Dijkstra
void dijkstra(struct Graph *graph, int source) {
  // Inicializa a distância do vértice de origem como 0
  graph->vertices[source].distance = 0;

  // Encontra o caminho mais curto para todos os vértices
  for (int i = 0; i < graph->numVertices - 1; i++) {
    // Encontra o vértice não visitado com a menor distância
    int u = findMinDistanceVertex(graph);

    // Marca o vértice como visitado
    graph->vertices[u].visited = true;

    // Relaxa as arestas do vértice atual
    for (int j = 0; j < graph->numEdges; j++) {
      if (graph->edges[j].source == u && !graph->vertices[graph->edges[j].destination].visited) {
        int alt = graph->vertices[u].distance + graph->edges[j].weight;
        if (alt < graph->vertices[graph->edges[j].destination].distance) {
          graph->vertices[graph->edges[j].destination].distance = alt;
        }
      }
    }
  }
}

int main() {
  struct Graph graph;
  initializeGraph(&graph, 6);

  addEdge(&graph, 0, 1, 4);
  addEdge(&graph, 0, 2, 2);
  addEdge(&graph, 1, 2, 1);
  addEdge(&graph, 1, 3, 5);
  addEdge(&graph, 2, 3, 8);
  addEdge(&graph, 2, 4, 10);
  addEdge(&graph, 3, 5, 2);
  addEdge(&graph, 4, 5, 6);

  int source = 0;

  dijkstra(&graph, source);

  printf("Distâncias dos vértices a partir do vértice %d:\n", source);
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vértice %d: %d\n", i, graph->vertices[i].distance);
  }

  return 0;
}
