#include "libmatches/choosegame.h"
#include "libmatches/commonrules.h"
#include "libmatches/gamepvp.h"
#include "libmatches/gamepvbe.h"
#include "libmatches/gamepvbh.h"
#include "libmatches/difficulty.h"
#include <stdio.h>

int main() {
  char gamevariant;
  char start;
  char diff;
  printf("\nПриветсвую в игре '100 Спичек'\n"
         "ПРАВИЛА: На столе 100 спичек, нужно брать НЕ МЕНЬШЕ 1 и НЕ БОЛЬШЕ 10\n"
         "Запрещается ввод символов, которые не являются числами\n"
         "Проигрывает тот, кто забирает последнюю спичку\n"
         "Начать игру: 's'\n");
  scanf("%s", &start);

  while (start != 's' && start != 'S') {
    printf("Неправильный ввод!\n");
    scanf("%s", &start);
  }

  printf("\nВыберите режим игры:\n"
         "Игра с другим игроком: нажмите 'm'\n"
         "Игра с ботом: нажмите 'b'\n");
  scanf("%s", &gamevariant);

  while (gamevariant != 'b' && gamevariant != 'm' && gamevariant != 'B' && gamevariant != 'M') {
    printf("Неправильный ввод!\n");
    scanf("%s", &gamevariant);
  }

  if (choosegame(gamevariant) == 1) {
    gamepvp();
  } else {
    printf("Выберите сложность игры с ботом\n"
             "Легкий бот: нажмите 'e'\n"
             "Сложный бот: нажмите 'h'\n");
    scanf("%s", &diff);
    while (diff != 'e' && diff != 'h' && diff != 'E' && diff != 'H') {
      printf("Неправильный ввод!\n");
      scanf("%s", &diff);
    }
    if (difficulty(diff) == 1) {
      gamepvbe();
    } else {
      gamepvbh();
    }
  }
  return 0;
}
