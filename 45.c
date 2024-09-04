#include <stdio.h>
#include <stdbool.h>

#define N 9

// Função para imprimir o Sudoku
void printSudoku(int grid[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Função para verificar se um número é seguro para colocar em uma posição específica
bool isSafe(int grid[N][N], int row, int col, int num) {
  // Verifica a linha
  for (int x = 0; x < N; x++) {
    if (grid[row][x] == num) {
      return false;
    }
  }

  // Verifica a coluna
  for (int x = 0; x < N; x++) {
    if (grid[x][col] == num) {
      return false;
    }
  }

  // Verifica o bloco 3x3
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }

  return true;
}

// Função recursiva para resolver o Sudoku
bool solveSudoku(int grid[N][N]) {
  // Encontra a próxima posição vazia
  int row, col;
  bool isEmpty = false;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        isEmpty = true;
        break;
      }
    }
    if (isEmpty) {
      break;
    }
  }

  // Se não houver posições vazias, o Sudoku está resolvido
  if (!isEmpty) {
    return true;
  }

  // Tenta colocar números de 1 a 9 na posição vazia
  for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
      // Coloca o número na posição
      grid[
