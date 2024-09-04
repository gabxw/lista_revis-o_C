#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Crie arrays temporários
  int L[n1], R[n2];

  // Copie os dados para os arrays temporários
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Mescle os arrays temporários de volta para arr[left...right]
  i = 0;  // Índice inicial do primeiro subarray
  j = 0;  // Índice inicial do segundo subarray
  k = left; // Índice inicial do subarray mesclado
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copie os elementos restantes de L[] se houver
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copie os elementos restantes de R[] se houver
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    // Encontre o ponto médio
    int mid = left + (right - left) / 2;

    // Ordene recursivamente as duas metades
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Mescle as duas metades ordenadas
    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array original: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  mergeSort(arr, 0, n - 1);

  printf("Array ordenado: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
