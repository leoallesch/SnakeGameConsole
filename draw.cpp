#include "Header.h"

#include <iostream>

using namespace std;

void draw(int width, int length, int x, int y, int fruitX, int fruitY, int& score) {
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
	system("cls");
}