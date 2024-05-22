#include "game.h"
#include <stdio.h>

// Main temporaria só pra testar se o jogo tava funcionando

int main() {
  Game game;
  int row, col;
  char winner;

  initGame(&game);

  while (1) {

    printBoard(&game);

    printf("Jogador %c, faça sua jogada (linha e coluna): ",
           game.currentPlayer);

    scanf("%d %d", &row, &col);

    if (!makeMove(&game, row - 1, col - 1)) {
      printf("Movimento inválido! Tente novamente.\n");
      continue;
    }

    winner = checkWinner(&game);

    if (winner != ' ') {
      printBoard(&game);
      printf("Jogador %c venceu!\n", winner);
      break;
    } else if (isBoardFull(&game)) {
      printBoard(&game);
      printf("Empate!\n");
      break;
    }
  }

  return 0;
}
