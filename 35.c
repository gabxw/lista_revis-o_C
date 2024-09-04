#include <stdio.h>

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Escolhendo o último elemento como pivô
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      // Trocando arr[i] e arr[j]
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  // Trocando arr[i+1] e arr[high] (o pivô)
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return (i + 1); // Retorna a posição do pivô
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // Particionando o array
    int pi = partition(arr, low, high);

    // Ordenando recursivamente as sub-arrays
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array original: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  quickSort(arr, 0, n - 1);

  printf("Array ordenado: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
