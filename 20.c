#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho, i;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tamanho);
  
  int vetor[tamanho];

  printf("Digite os numeros dos elementos do vetor: \n");
  for(int i = 0; i < tamanho; i++){
    printf("Elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
    
  }
  printf("Vetor original: ");
  for(int i = 0; i < tamanho; i++){
    printf("%d, ", vetor[i]);
  }
  printf("\n");

  for(int i = 0; i < tamanho - 1; i++){
    for(int j = 0; j < tamanho - i - 1; j++){
      if(vetor[j] > vetor[j + 1]){
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
  printf("Vetor ordenado: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");


  
  return 0;
}
  
  
  
