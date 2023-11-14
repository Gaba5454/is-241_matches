#include "libmatches/gamepvp.h"
#include "libmatches/checktruth.h"
#include "libmatches/commonrules.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int gamepvp() {
  int bunch = 100;
  printf("\nИгра с другим игроком\n");
  while (bunch != 0) {
    printf("\nХод первого игрока\n");
    bunch = player(bunch);
    if (bunch != 0) {
      printf("\nХод второго игрока\n");
      bunch = player(bunch);
    }
    else {
      printf("Победил второй игрок!\n");
      printf("Хотите реванш?\nДа - 'y' Нет - 'n'\n");
      restart(1, ' ');
      return 2;
    }
  }
  printf("Победил первый игрок!\n");
  printf("Хотите реванш?\nДа - 'y' Нет - 'n'\n");
  restart(1, ' ');
  return 1;
}

int player(int bunch) {
  int checkdigit = 0;
  int playerchoose;
  printf("Спичек в куче: %d\nСколько спичек убрать?\n", bunch);
  while (checkdigit != 1) {
    scanf("%d", &playerchoose);
    checkdigit = check(playerchoose, bunch);
    if (checkdigit != 1)
      printf("Неправильный ввод!\n");
  }
  bunch -= playerchoose;
  return bunch;
}
