#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#define SIZE 3

typedef struct {
  char board[SIZE][SIZE];
  char currentPlayer;
} Game;

void initGame(Game *game);
void printBoard(Game *game);
int makeMove(Game *game, const int row, const int col);
char checkWinner(Game *game);
int isBoardFull(Game *game);

#endif