#include <stdio.h>
#include <stdlib.h>

int choosegame(char game) {
	if (game == 'm' || game == 'M')
		return 1;
	else
		return 2;
}
