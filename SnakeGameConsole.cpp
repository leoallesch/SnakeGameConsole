// SnakeGameConsole.cpp
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

bool snake = false;
int score;

const int width = 60;
const int length = 20;
char repeat = 'y';
int x, y, fruitX, fruitY;
int nTail;

vector <int> tailX;
vector <int> tailY;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() {
	snake = true;
	score = 0;
	nTail = 1;

	x = width / 2;
	y = length / 2;

	tailX.push_back(x);
	tailY.push_back(y);
	tailX.push_back(x);
	tailY.push_back(y);

	fruitX = rand() % width;
	fruitY = rand() % length;

	while (fruitX == x) {
		fruitX = rand() % width;
	}
	while (fruitY == y) {
		fruitY = rand() % length;
	}
}

void draw() {
	system("cls");
	//top border
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
			else {
				bool print = false;
				for (int z = 1; z < nTail; z++) {
					if (tailX[z] == j && tailY[z] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print) {
					cout << " ";
				}
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
	tailX[0] = x;
	tailY[0] = y;
	if (score > 0) {
		for (int i = nTail - 1; i > 0; i--) {
			tailX[i] = tailX[i - 1];
			tailY[i] = tailY[i - 1];
		}
	}

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
	default:
		break;
	}

	if (x == fruitX && y == fruitY) {
		score++;
		nTail++;

		fruitX = rand() % width;
		fruitY = rand() % length;

		while (fruitX == x) {
			fruitX = rand() % width;
		}
		while (fruitY == y) {
			fruitY = rand() % length;
		}

		tailX.push_back(tailX[nTail - 1]);
		tailY.push_back(tailY[nTail - 1]);
	}
	
	if (x < 0 || x > width - 1) {
		snake = false;
	}
	else if (y < 0 || y > length - 1) {
		snake = false;
	}

	for (int i = 1; i < nTail; i++) {
		if (x == tailX[i] && y == tailY[i]) {
			snake = false;
		}
	}
}
int main()
{
	setup();
	while (repeat == 'y' || repeat == 'Y') {
		while (snake == true) {
			draw();
			input();
			logic();
		}
		cout << "Would you like to play again (Y/N): ";
		cin >> repeat;
		if (repeat == 'y' || repeat == 'Y') {
			snake = true;
			setup();
		}
	}
	return 0;
}