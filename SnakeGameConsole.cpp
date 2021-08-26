// SnakeGameConsole.cpp
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

bool snake = false;
int score;

const int width = 75;
const int length = 25;
int x, y, fruitX, fruitY;
int prevX, prevY;
vector <int> tailX;
vector <int> tailY;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() {
	snake = true;
	score = 0;

	x = width/2;
	y = length/2;

	tailX.push_back(x);
	tailY.push_back(y);

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
				cout << "F";
			}
			else if (j == prevX && i == prevY) {
				cout << "o";
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
		tailX.push_back(tailX[tailX.size()-1]);
		tailY.push_back(tailY[tailY.size()-1]);

		while (fruitX == x) {
			fruitX = rand() % (width - 1) + 1;
		}
		while (fruitY == y) {
			fruitY = rand() % (length - 1) + 1;
		}
	}
	
	tailX[0] = x;
	tailY[0] = y;

	if (score > 0) {
		for (int i = (tailX.size()-1); i > 0; i--) {
			tailX[i] = tailX[i - 1];
		}
		for (int i = (tailY.size()-1); i > 0; i--) {
			tailY[i] = tailY[i - 1];
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
	system("cls");
	for (int i = 0; i < (tailX.size()-1); i++) {
		cout << tailX[i] << endl;
	}
	
	return 0;
}

