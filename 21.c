#include <stdio.h>

int busca_linear(int arr[], int n, int alvo) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == alvo) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int n = sizeof(arr) / sizeof(arr[0]);
  int alvo = 12;

  int indice = busca_linear(arr, n, alvo);

  if (indice != -1) {
    printf("Elemento encontrado no índice: %d\n", indice);
  } else {
    printf("Elemento não encontrado no array.\n");
  }

  return 0;
}
