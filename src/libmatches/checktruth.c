#include <ctype.h>
#include <stdio.h>

int check(int checkvalue, int amount) {
  if (checkvalue >= 1 && checkvalue <= 10 && checkvalue <= amount)
    return 1;
  if (checkvalue >= 1 && checkvalue <= 10 && checkvalue >= amount) {
    return 2;
  }
  if (checkvalue < 1 || checkvalue > 10) {
    return 3;
  }
  return 0;
}
