#include <stdio.h>

int difficulty(char diff) {
  if (diff == 'e' || diff == 'E')
    return 1;
  else
    return 2;
}
