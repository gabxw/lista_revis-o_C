Jogo da Velha: Implemente o jogo da velha para dois jogadores.#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// Define os jogadores
enum Player { X, O };

// Função para imprimir o tabuleiro
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  printf("  1 2 3\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Função para verificar se uma posição no tabuleiro está vazia
int isPositionEmpty(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
  return board[row][col] == ' ';
}

// Função para fazer uma jogada
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], enum Player player, int row, int col) {
  board[row][col] = (player == X) ? 'X' : 'O';
}

// Função para verificar se um jogador ganhou
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], enum Player player) {
  char mark = (player == X) ? 'X' : 'O';

  // Verifica linhas
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
      return 1;
    }
  }

  // Verifica colunas
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
      return 1;
    }
  }

  // Verifica diagonais
  if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
      (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
    return 1;
  }

  return 0;
}

// Função para verificar se o tabuleiro está cheio
int isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return
