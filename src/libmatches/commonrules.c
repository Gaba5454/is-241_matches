#include "libmatches/gamepvp.h"
#include "libmatches/gamepvbe.h"
#include "libmatches/gamepvbh.h"
#include <stdio.h>

int restart(int gametype, char flag) {
  if (flag != 'n' && flag != 'y' && flag != 'N' && flag != 'Y') {
    scanf("%s", &flag);
    while (flag != 'n' && flag != 'y' && flag != 'N' && flag != 'Y') {
      printf("Неправильный ввод!\n");
      scanf("%s", &flag);
    }
  }
  if (flag == 'y' || flag == 'Y') {
    if (gametype == 1)
      gamepvp();
    else if (gametype == 2)
      gamepvbe();
    else if (gametype == 3)
      gamepvbh();
  }
  return 0;
}
