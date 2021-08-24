// SnakeGameConsole.cpp
#include <iostream>

#include "Header.h"

using namespace std;

bool snake = false;
int score;

const int width = 75;
const int length = 25;
int x, y, fruitX, fruitY;

enum direction { stop = 0, left, right, up, down };
direction dir = stop;

int main()
{
	setup(snake,x,y,fruitX,fruitY,width,length,score);
	while (snake == true) {
		draw(width, length, x, y, fruitX, fruitY, score);
	}
	
	return 0;
}

