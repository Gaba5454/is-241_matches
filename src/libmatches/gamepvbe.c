#include "libmatches/gamepvbe.h"
#include "libmatches/gamepvp.h"
#include "libmatches/commonrules.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gamepvbe() {
  int bunch = 100;
  printf("\nИгра с легким ботом\n");
  while (bunch != 0) {
    printf("\nХод игрока\n");
    bunch = player(bunch);
    if (bunch != 0) {
      printf("\nХод бота\n");
      bunch = boteturn(bunch);
    }
    else {
      printf("Победил бот!\n");
      printf("Хотите реванш?\nДа - 'y' Нет - 'n'\n");
      restart(2, ' ');
      return 2;
    }
  }
  printf("Победил игрок!\n");
  printf("Хотите реванш?\nДа - 'y' Нет - 'n'\n");
  restart(2, ' ');
  return 1;
}

int boteturn(int bunch) {
  int botchoose;
  printf("Спичек в куче: %d\n", bunch);
  if (bunch > 10) {
    srand(time(NULL));
    botchoose = rand() % 10 + 1;
    bunch -= botchoose;
    printf("Бот убрал %d спичек\n", botchoose);
    return bunch;
  } else {
    srand(time(NULL));
    botchoose = rand() % bunch + 1;
    bunch -= botchoose;
    printf("%d\n", botchoose);
    return bunch;
  }
}
