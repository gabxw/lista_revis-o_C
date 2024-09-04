#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
  int items[MAX_SIZE];
  int front;
  int rear;
};

// Inicializa a fila
void initialize(struct Queue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

// Verifica se a fila está vazia
int isEmpty(struct Queue *queue) {
  return queue->front == -1 && queue->rear == -1;
}

// Verifica se a fila está cheia
int isFull(struct Queue *queue) {
  return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Insere um item na fila
void enqueue(struct Queue *queue, int item) {
  if (isFull(queue)) {
    printf("Fila está cheia\n");
    return;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->rear = (queue->rear + 1) % MAX_SIZE;
  queue->items[queue->rear] = item;
}

// Remove e retorna o item da frente da fila
int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Fila está vazia\n");
    return -1;
  }
  int item = queue->items[queue->front];
  if (queue->front == queue->rear) {
    initialize(queue);
  } else {
    queue->front = (queue->front + 1) % MAX_SIZE;
  }
  return item;
}

// Retorna o item da frente da fila sem removê-lo
int peek(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Fila está vazia\n");
    return -1;
  }
  return queue->items[queue->front];
}

int main() {
  struct Queue queue;
  initialize(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  printf("Item da frente: %d\n", peek(&queue));
  printf("Item removido: %d\n", dequeue(&queue));
  printf("Item da frente: %d\n", peek(&queue));

  return 0;
}
