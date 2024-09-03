#include <stdio.h>

int busca_binaria(int arr[], int n, int alvo) {
  int esquerda = 0;
  int direita = n - 1;

  while (esquerda <= direita) {
    int meio = esquerda + (direita - esquerda) / 2;

    if (arr[meio] == alvo) {
      return meio;
    } else if (arr[meio] < alvo) {
      esquerda = meio + 1;
    } else {
      direita = meio - 1;
    }
  }

  return -1;
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int n = sizeof(arr) / sizeof(arr[0]);
  int alvo = 23;

  int indice = busca_binaria(arr, n, alvo);

  if (indice != -1) {
    printf("Elemento encontrado no índice: %d\n", indice);
  } else {
    printf("Elemento não encontrado no array.\n");
  }

  return 0;
}
