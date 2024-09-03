#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numero_secreto, palpite, tentativas = 0;

  // Inicializa o gerador de números aleatórios
  srand(time(NULL));

  // Gera um número secreto aleatório entre 1 e 100
  numero_secreto = rand() % 100 + 1;

  printf("Bem-vindo ao jogo de adivinhação!\n");
  printf("Estou pensando em um número entre 1 e 100.\n");

  // Loop do jogo
  do {
    printf("Digite seu palpite: ");
    scanf("%d", &palpite);

    tentativas++;

    if (palpite < numero_secreto) {
      printf("Muito baixo! Tente novamente.\n");
    } else if (palpite > numero_secreto) {
      printf("Muito alto! Tente novamente.\n");
    } else {
      printf("Parabéns! Você acertou em %d tentativas.\n", tentativas);
    }
  } while (palpite != numero_secreto);

  return 0;
}
