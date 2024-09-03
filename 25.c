#include <stdio.h>

int main() {
  int decimal, i = 0, binario[32];

  printf("Digite um número decimal: ");
  scanf("%d", &decimal);

  while (decimal > 0) {
    binario[i] = decimal % 2;
    decimal /= 2;
    i++;
  }

  printf("O número binário equivalente é: ");

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binario[j]);
  }

  printf("\n");

  return 0;
}
