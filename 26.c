#include <stdio.h>

int main() {
  int linhas, colunas;

  printf("Digite o número de linhas das matrizes: ");
  scanf("%d", &linhas);
  printf("Digite o número de colunas das matrizes: ");
  scanf("%d", &colunas);

  int matriz1[linhas][colunas], matriz2[linhas][colunas], soma[linhas][colunas];

  // Leitura da primeira matriz
  printf("Digite os elementos da primeira matriz:\n");
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      scanf("%d", &matriz1[i][j]);
    }
  }

  // Leitura da segunda matriz
  printf("Digite os elementos da segunda matriz:\n");
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      scanf("%d", &matriz2[i][j]);
    }
  }

  // Cálculo da soma das matrizes
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      soma[i][j] = matriz1[i][j] + matriz2[i][j];
    }
  }

  // Impressão da matriz resultante
  printf("A matriz resultante da soma é:\n");
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%d ", soma[i][j]);
    }
    printf("\n");
  }

  return 0;
}
