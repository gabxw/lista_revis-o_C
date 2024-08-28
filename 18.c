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

  printf("Digite o primeiro n�mero: ");
  scanf("%d", &num1);

  printf("Digite o segundo n�mero: ");
  scanf("%d", &num2);

  resultado = mmc(num1, num2);

  printf("O MMC de %d e %d �: %d\n", num1, num2, resultado);

  return 0;
}
