#include <locale.h>
#include <stdio.h>

int main() {
  int num1;
  int num2;
  
  
  printf("Insira o primeiro n�mero");
  scanf("%d", &num1);
  printf("Insira o segundo n�mero");
  scanf("%d", &num2);
  int soma = num1 + num2;
  printf("A soma deles ser�: %d", soma);
  
  return 0;
}
