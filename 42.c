#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Inicializa o gerador de números aleatórios com a hora atual
  srand(time(NULL));

  // Gera um número aleatório entre 1 e 100
  int randomNumber = rand() % 100 + 1;

  printf("Número aleatório: %d\n", randomNumber);

  return 0;
}
