#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Avalia uma expressão pós-fixa
int evaluatePostfix(char *postfix) {
  struct Stack stack;
  initialize(&stack);
  int i = 0;

  while (postfix[i] != '\0') {
    if (postfix[i] >= '0' && postfix[i] <= '9') {
      push(&stack, postfix[i] - '0');
    } else {
      int operand2 = pop(&stack);
      int operand1 = pop(&stack);
      switch (postfix[i]) {
        case '+':
          push(&stack, operand1 + operand2);
          break;
        case '-':
          push(&stack, operand1 - operand2);
          break;
        case '*':
          push(&stack, operand1 * operand2);
          break;
        case '/':
          push(&stack, operand1 / operand2);
          break;
      }
    }
    i++;
  }

  return pop(&stack);
}

int main() {
  char postfix[MAX_SIZE];

  printf("Digite a expressão pós-fixa: ");
  fgets(postfix, MAX_SIZE, stdin);
  postfix[strcspn(postfix, "\n")] = '\0';

  int result = evaluatePostfix(postfix);

  printf("Resultado: %d\n", result);

  return 0;
}
