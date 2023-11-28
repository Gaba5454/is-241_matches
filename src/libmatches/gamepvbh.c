#include "src/libmatches/gamepvbh.h"
#include "src/libmatches/gamepvp.h"
#include "src/libmatches/commonrules.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gamepvbh() {
  int bunch = 100;
  int bunchtemp;
  int playerchoose;
  printf("\nИгра с умным ботом\n");
  while (bunch != 0) {
    printf("\nХод игрока\n");
    bunchtemp = bunch;
    bunch = player(bunch);
    playerchoose = bunchtemp - bunch;
    if (bunch != 0) {
      printf("\nХод бота\n");
      bunch = bothturn(bunch, playerchoose);
    }
    else {
      printf("Победил бот!\n");
      printf("Хотите реванш?\nДа - 'y' Нет - 'n'\n");
      restart(3, ' ');
      return 2;
    }
  }
  printf("Победил игрок!\n");
  printf("Хотите реванш?\nДа - 'y' Нет - 'n'\n");
  restart(3, ' ');
  return 1;
}

int bothturn(int bunchofmatches, int playerchoose) {
  int botchoose;
  printf("Спичек в куче: %d\n", bunchofmatches);
  if (bunchofmatches > 92) {
    if (playerchoose >= 8) {
      if (playerchoose == 8)
        botchoose = 10;
      else if (playerchoose == 9)
        botchoose = 9;
      else if (playerchoose == 10)
        botchoose = 8;
      bunchofmatches -= botchoose;
      printf("Бот убрал %d спичек\n", botchoose);
      return bunchofmatches;
    }
    botchoose = 8 - playerchoose;
    bunchofmatches -= botchoose;
    printf("Бот убрал %d спичек\n", botchoose);
    return bunchofmatches;
  } 
  else if (bunchofmatches <= 92 && bunchofmatches > 12) {
    if (playerchoose == 10) {
      botchoose = 10;
      bunchofmatches -= botchoose;
      printf("Бот убрал %d спичек\n", botchoose);
      return bunchofmatches;
    }
    botchoose = 10 - playerchoose;
    bunchofmatches -= botchoose;
    printf("Бот убрал %d спичек\n", botchoose);
    return bunchofmatches;
  }
  else if (bunchofmatches <= 12) {
    if (bunchofmatches == 12) {
      botchoose = 10;
      bunchofmatches -= botchoose;
      printf("Бот убрал %d спичек\n", botchoose);
      return bunchofmatches;
    }
    else if (bunchofmatches == 1) {
      botchoose = 1;
      bunchofmatches -= botchoose;
      printf("Бот убрал %d спичек\n", botchoose);
      return bunchofmatches;
    } else {
    botchoose = bunchofmatches - 1;
    bunchofmatches -= botchoose;
    printf("Бот убрал %d спичек\n", botchoose);
    return bunchofmatches;
    }
  }
  return 0;
}
