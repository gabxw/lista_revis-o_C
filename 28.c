#include <stdio.h>

int main() {
  int matriz[2][2];
  int determinante;

  printf("Digite os elementos da matriz 2x2:\n");

  // Leitura dos elementos da matriz
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  // Cálculo do determinante
  determinante = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

  // Impressão do determinante
  printf("O determinante da matriz é: %d\n", determinante);

  return 0;
}
