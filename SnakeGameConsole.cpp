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

enum direction { stop = 0, left, right, up, down };
direction dir;

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

	cout << "Score: " << score;
}

void input() {

}

void logic() {

}

int main()
{
	setup();
	while (snake == true) {
		draw();
	}
	
	return 0;
}

