// SnakeGameConsole.cpp
#include <iostream>

#include "Header.h"

bool snake = false;
int score;

const int width = 75;
const int length = 25;
int x, y, fruitX, fruitY;

int main()
{
	setup(snake,x,y,fruitX,fruitY,width,length,score);
	draw(width, length, x, y, fruitX, fruitY,score);
	return 0;
}

