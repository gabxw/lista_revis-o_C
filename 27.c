#include <stdio.h>

int main() {
  int linhas1, colunas1, linhas2, colunas2;

  printf("Digite o número de linhas da primeira matriz: ");
  scanf("%d", &linhas1);
  printf("Digite o número de colunas da primeira matriz: ");
  scanf("%d", &colunas1);
  printf("Digite o número de linhas da segunda matriz: ");
  scanf("%d", &linhas2);
  printf("Digite o número de colunas da segunda matriz: ");
  scanf("%d", &colunas2);

  // Verifica se as matrizes são compatíveis para multiplicação
  if (colunas1 != linhas2) {
    printf("As matrizes não são compatíveis para multiplicação.\n");
    return 1; // Retorna um código de erro
  }

  int matriz1[linhas1][colunas1], matriz2[linhas2][colunas2], produto[linhas1][colunas2];

  // Leitura da primeira matriz
  printf("Digite os elementos da primeira matriz:\n");
  for (int i = 0; i < linhas1; i++) {
    for (int j = 0; j < colunas1; j++) {
      scanf("%d", &matriz1[i][j]);
    }
  }

  // Leitura da segunda matriz
  printf("Digite os elementos da segunda matriz:\n");
  for (int i = 0; i < linhas2; i++) {
    for (int j = 0; j < colunas2; j++) {
      scanf("%d", &matriz2[i][j]);
    }
  }

  // Cálculo do produto das matrizes
  for (int i = 0; i < linhas1; i++) {
    for (int j = 0; j < colunas2; j++) {
      produto[i][j] = 0;
      for (int k = 0; k < colunas1; k++) {
        produto[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }

  // Impressão da matriz resultante
  printf("A matriz resultante da multiplicação é:\n");
  for (int i = 0; i < linhas1; i++) {
    for (int j = 0; j < colunas2; j++) {
      printf("%d ", produto[i][j]);
    }
    printf("\n");
  }

  return 0;
}
