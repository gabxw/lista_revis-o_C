#include <stdio.h>

int mmc(int a, int b) {
  int maior, menor, i;

  maior = (a > b) ? a : b;
  menor = (a < b) ? a : b;


  for (i = maior; ; i += maior) {
    if (i % menor == 0) {
      return i;
    }
  }
}

int main() {
  int num1, num2, resultado;

  printf("Digite o primeiro número: ");
  scanf("%d", &num1);

  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  resultado = mmc(num1, num2);

  printf("O MMC de %d e %d é: %d\n", num1, num2, resultado);

  return 0;
}
