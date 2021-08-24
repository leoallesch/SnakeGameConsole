#include "Header.h"

#include <stdlib.h>

void setup(bool& snake, int& x, int& y, int& fruitX, int& fruitY, int width, int length, int& score) {
	snake = true;
	score = 0;

	x = rand() % (width - 1) + 1;
	y = rand() % (length - 1) + 1;
	fruitX = rand() % (width - 1) + 1;
	fruitY = rand() % (length - 1) + 1;

	while (fruitX == x) {
		fruitX = rand() % (width - 1) + 1;
	}
	while (fruitY == y) {
		fruitY = rand() % (length - 1) + 1;
	}

}