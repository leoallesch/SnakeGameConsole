// SnakeGameConsole.cpp
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

bool snake = false;
int score;

const int width = 75;
const int length = 25;
int x, y, fruitX, fruitY;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() {
	snake = true;
	score = 0;

	x = width/2;
	y = length/2;
	fruitX = rand() % (width - 1) + 1;
	fruitY = rand() % (length - 1) + 1;

	while (fruitX == x) {
		fruitX = rand() % (width - 1) + 1;
	}
	while (fruitY == y) {
		fruitY = rand() % (length - 1) + 1;
	}

}

void draw() {
	system("cls");
	for (int i = 0; i < width; i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == (width - 1)) {
				cout << "*";
			}
			else if (j == x && i == y) {
				cout << "O";
			}
			else if (j == fruitX && i == fruitY) {
				cout << "P";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) {
		cout << "*";
	}
	cout << endl;

	cout << "Score: " << score << endl;
}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
			case 'w':
				if (dir != DOWN) {
					dir = UP;
				}
				break;
			case 'a':
				if (dir != RIGHT) {
					dir = LEFT;
				}
				break;
			case 's':
				if (dir != UP) {
					dir = DOWN;
				}
				break;
			case 'd':
				if (dir != LEFT) {
					dir = RIGHT;
				}
				break;
			case 'x':
				dir = STOP;
				break;
			default:
				break;
		}
	}
}

void logic() {
	switch (dir) {
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case STOP:
			//snake = false;
			break;
		default:
			break;
	}

	if (x < 0 || x > width-1) {
		snake = false;
	}
	else if (y < 0 || y > length-1) {
		snake = false;
	}

	if (x == fruitX && y == fruitY) {
		score++;
		fruitX = rand() % (width - 1) + 1;
		fruitY = rand() % (length - 1) + 1;

		while (fruitX == x) {
			fruitX = rand() % (width - 1) + 1;
		}
		while (fruitY == y) {
			fruitY = rand() % (length - 1) + 1;
		}
	}
}

int main()
{
	setup();
	while (snake == true) {
		draw();
		input();
		logic();
	}
	
	return 0;
}

