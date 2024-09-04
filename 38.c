#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
  char items[MAX_SIZE];
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
void push(struct Stack *stack, char item) {
  if (isFull(stack)) {
    printf("Pilha está cheia\n");
    return;
  }
  stack->top++;
  stack->items[stack->top] = item;
}

// Remove e retorna o item do topo da pilha
char pop(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Pilha está vazia\n");
    return -1;
  }
  char item = stack->items[stack->top];
  stack->top--;
  return item;
}

// Retorna o item do topo da pilha sem removê-lo
char peek(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Pilha está vazia\n");
    return -1;
  }
  return stack->items[stack->top];
}

// Verifica a precedência de um operador
int precedence(char operator) {
  if (operator == '+' || operator == '-') {
    return 1;
  } else if (operator == '*' || operator == '/') {
    return 2;
  } else if (operator == '^') {
    return 3;
  } else {
    return 0;
  }
}

// Converte uma expressão infixa para pós-fixa
void infixToPostfix(char *infix, char *postfix) {
  struct Stack stack;
  initialize(&stack);
  int i = 0, j = 0;

  while (infix[i] != '\0') {
    if (infix[i] >= '0' && infix[i] <= '9') {
      postfix[j++] = infix[i];
    } else if (infix[i] == '(') {
      push(&stack, infix[i]);
    } else if (infix[i] == ')') {
      while (!isEmpty(&stack) && peek(&stack) != '(') {
        postfix[j++] = pop(&stack);
      }
      if (!isEmpty(&stack) && peek(&stack) == '(') {
        pop(&stack);
      }
    } else {
      while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack))) {
        postfix[j++] = pop(&stack);
      }
      push(&stack, infix[i]);
    }
    i++;
  }

  while (!isEmpty(&stack)) {
    postfix[j++] = pop(&stack);
  }
  postfix[j] = '\0';
}

int main() {
  char infix[MAX_SIZE];
  char postfix[MAX_SIZE];

  printf("Digite a expressão infixa: ");
  fgets(infix, MAX_SIZE, stdin);
  infix[strcspn(infix, "\n")] = '\0';

  infixToPostfix(infix, postfix);

  printf("Expressão pós-fixa: %s\n", postfix);

  return 0;
}
