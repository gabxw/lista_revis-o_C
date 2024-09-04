#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
  int items[MAX_SIZE];
  int top;
};

// Inicializa a pilha
void initialize(struct Stack *stack) {
  stack->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack *stack) {
  return stack->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *stack) {
  return stack->top == MAX_SIZE - 1;
}

// Insere um item na pilha
void push(struct Stack *stack, int item) {
  if (isFull(stack)) {
    printf("Pilha está cheia\n");
    return;
  }
  stack->top++;
  stack->items[stack->top] = item;
}

// Remove e retorna o item do topo da pilha
int pop(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Pilha está vazia\n");
    return -1;
  }
  int item = stack->items[stack->top];
  stack->top--;
  return item;
}

// Retorna o item do topo da pilha sem removê-lo
int peek(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Pilha está vazia\n");
    return -1;
  }
  return stack->items[stack->top];
}

int main() {
  struct Stack stack;
  initialize(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("Item do topo: %d\n", peek(&stack));
  printf("Item removido: %d\n", pop(&stack));
  printf("Item do topo: %d\n", peek(&stack));

  return 0;
}
