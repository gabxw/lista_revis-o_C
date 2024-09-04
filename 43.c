#include <stdio.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int longestIncreasingSubsequence(int arr[], int n) {
  int lis[n];
  lis[0] = 1;

  // Calcula o comprimento da maior subsequência crescente que termina em cada índice
  for (int i = 1; i < n; i++) {
    lis[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  // Encontra o comprimento máximo da subsequência crescente
  int maxLength = lis[0];
  for (int i = 1; i < n; i++) {
    maxLength = max(maxLength, lis[i]);
  }

  return maxLength;
}

int main() {
  int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("A maior subsequência crescente é: %d\n", longestIncreasingSubsequence(arr, n));

  return 0;
}
