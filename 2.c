#include <locale.h>
#include <stdio.h>

int main() {
  int num1;
  int num2;
  
  
  printf("Insira o primeiro número");
  scanf("%d", &num1);
  printf("Insira o segundo número");
  scanf("%d", &num2);
  int soma = num1 + num2;
  printf("A soma deles será: %d", soma);
  
  return 0;
}
