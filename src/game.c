#include "game.h"
#include <stdio.h>

void initGame(Game *game) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      game->board[i][j] = ' ';
    }
  }
  game->currentPlayer = 'X';
}

int makeMove(Game *game, int row, int col) {
  if (row < 0 || row >= SIZE || col < 0 || col >= SIZE ||
      game->board[row][col] != ' ') {
    return 1;
  }
  game->board[row][col] = game->currentPlayer;
  game->currentPlayer = (game->currentPlayer == 'X') ? 'O' : 'X';
  return 0;
}

char checkWinner(Game *game) {
  // Verifica linhas e colunas
  for (int i = 0; i < SIZE; i++) {
    if (game->board[i][0] != ' ' && game->board[i][0] == game->board[i][1] &&
        game->board[i][1] == game->board[i][2]) {
      return game->board[i][0];
    }
    if (game->board[0][i] != ' ' && game->board[0][i] == game->board[1][i] &&
        game->board[1][i] == game->board[2][i]) {
      return game->board[0][i];
    }
  }
  // Verifica diagonais
  if (game->board[0][0] != ' ' && game->board[0][0] == game->board[1][1] &&
      game->board[1][1] == game->board[2][2]) {
    return game->board[0][0];
  }
  if (game->board[0][2] != ' ' && game->board[0][2] == game->board[1][1] &&
      game->board[1][1] == game->board[2][0]) {
    return game->board[0][2];
  }
  return ' ';
}

int isBoardFull(Game *game) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (game->board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

void printBoard(Game *game) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf(" %c ", game->board[i][j]);
      if (j < SIZE - 1)
        printf("|");
    }
    printf("\n");
    if (i < SIZE - 1) {
      for (int j = 0; j < SIZE; j++) {
        printf("---");
        if (j < SIZE - 1)
          printf("+");
      }
      printf("\n");
    }
  }
  printf("\n");
}