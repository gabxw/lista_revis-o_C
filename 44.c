#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Estrutura para representar as coordenadas de uma casa no tabuleiro
struct Position {
  int row;
  int col;
};

// Função para imprimir o tabuleiro
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%2d ", board[i][j]);
    }
    printf("\n");
  }
}

// Função para verificar se uma posição é válida no tabuleiro
int isValidPosition(struct Position position) {
  return position.row >= 0 && position.row < BOARD_SIZE &&
         position.col >= 0 && position.col < BOARD_SIZE;
}

// Função para encontrar as posições válidas para o próximo movimento do cavalo
int findValidMoves(int board[BOARD_SIZE][BOARD_SIZE], struct Position currentPosition, struct Position validMoves[], int *moveCount) {
  // Define os possíveis movimentos do cavalo
  int rowMoves[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
  int colMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

  // Verifica cada possível movimento
  for (int i = 0; i < 8; i++) {
    struct Position nextPosition = { currentPosition.row + rowMoves[i], currentPosition.col + colMoves[i] };

    // Se a posição for válida e ainda não foi visitada
    if (isValidPosition(nextPosition) && board[nextPosition.row][nextPosition.col] == 0) {
      validMoves[*moveCount] = nextPosition;
      (*moveCount)++;
    }
  }

  return *moveCount;
}

// Função para simular os movimentos do cavalo
void simulateHorseMoves(int board[BOARD_SIZE][BOARD_SIZE], struct Position startPosition) {
  int moveCount = 0;
  struct Position validMoves[8];

  // Marca a posição inicial como visitada
  board[startPosition.row][startPosition.col] = 1;

  // Encontra os movimentos válidos da posição inicial
  moveCount = findValidMoves(board, startPosition, validMoves, &moveCount);

  // Itera sobre os movimentos válidos
  for (int i = 0; i < moveCount; i++) {
    // Move o cavalo para a próxima posição válida
    struct Position nextPosition = validMoves[i];
    board[nextPosition.row][nextPosition.col] = board[startPosition.row][startPosition.col] + 1;

    // Recursivamente simula os movimentos a partir da nova posição
    simulateHorseMoves(board, nextPosition);
  }
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {0};
  struct Position startPosition = { 0, 0 };

  // Simula os movimentos do cavalo a partir da posição inicial
  simulateHorseMoves(board, startPosition);

  // Imprime o tabuleiro com os números de movimentos
  printBoard(board);

  return 0;
}
