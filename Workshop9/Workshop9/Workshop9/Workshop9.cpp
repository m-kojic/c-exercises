#include <conio.h>
#include <iostream>
#include <vector>
#include<Windows.h>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<bool>> grid;

enum concol // enumeration type, gives names to the built-in colours 
{
	black = 0, dark_blue = 1, dark_green = 2, dark_cyan = 3, dark_red = 4, dark_purple = 5, dark_yellow = 6, light_gray = 7, gray = 8, blue = 9, green = 10, cyan = 11, red = 12, purple = 13, yellow = 14, white = 15
};

void setColours(concol textcol, concol backcol) // set text/background colour 
{ // Combine the two 4-bit numbers into a single 8-bit number 
  // If backcol is abcd in binary, and textcol is efgh, the result is abcdefgh 
	unsigned short colours = (backcol << 4) | textcol;
	// set the attributes for the console 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colours);
}

uint getBoardSize() {
	cout << "Please enter the board size (between 5 and 15)" << endl;
	uint size;
	cin >> size;
	while (size < 5 || size > 15) {
		cout << "Size should be between 5 and 15; what shall it be?" << endl;
		cin >> size;
	}
	return size;
}

//uint countNeighbours(grid& board, uint x, uint y) {
//	uint count = 0;
//	for (uint i = 0; i < 3; i++)
//		for (uint j = 0; j < 3; j++) {
//			bool isWithinMapBoundaries = (x + i <= board.size()) && (y + j < board.size());
//			if ((x + i > 0) && (y + j > 0) && isWithinMapBoundaries && board[x + i - 1][y + j - 1])
//				count++;
//		}
//	cout << "Pos X: " << x << ", Y: " << y << ", Count: " << count << endl;
//	return count;
//}

uint countNeighbours(grid& board, uint x, uint y) {
	uint count = 0;
	for (int yMap = -1; yMap <= 1; yMap++)
		for (int xMap = -1; xMap <= 1; xMap++) {
			bool isWithinMapWidth = x + xMap >= 0 && x + xMap < board.size();
			bool isWithinMapHeight = y + yMap >= 0 && y + yMap < board.size();
			bool isPlayer = (xMap == 0) && (yMap == 0);
			if (isWithinMapWidth && isWithinMapHeight) {
				if (board[x + xMap][y + yMap] && !isPlayer) {
					count++;
				}
			}
		}
	//cout << "Pos X: " << x << ", Y: " << y << ", Count: " << count << endl;
	return count;
}

bool alive(grid& board, uint x, uint y) {
	uint count = countNeighbours(board, x, y);
	return ((count >= 2 && count <= 3) || (board[x][y] == false && count == 3));
}

void step(grid& current, grid& next) {
	for (uint x = 0; x < current.size(); x++)
		for (uint y = 0; y < current.size(); y++)
			next[x][y] = alive(current, x, y);
}

void draw(grid& board, uint cursorX, uint cursorY) {
	system("cls");
	for (uint y = 0; y < board.size(); y++) {
		for (uint x = 0; x < board.size(); x++) {
			setColours(white, ((x == cursorX && y == cursorY) ? dark_blue : black));
			cout << (board[x][y] ? "O" : " ");
		}
		cout << endl;
	}
}

int main() {
	uint size = getBoardSize();
	grid grids[2];
	grids[0].resize(size, vector<bool>(size, false));
	grids[1].resize(size, vector<bool>(size, false));
	uint currentIndex = 0;
	uint cursorX = 0, cursorY = 0;
	bool done = false;
	while (!done) {
		draw(grids[currentIndex], cursorX, cursorY);
		char input = _getch();
		switch (input) {
		case 'q':
			done = true;
			break;
		case 'w':
			if (cursorY > 0)
				cursorY--;
			break;
		case 'a':
			if (cursorX > 0)
				cursorX--;
			break;
		case 's':
			if (cursorY < size - 1)
				cursorY++;
			break;
		case 'd':
			if (cursorX < size - 1)
				cursorX++;
			break;
		case 'e':
			step(grids[currentIndex], grids[1 - currentIndex]);
			currentIndex = 1 - currentIndex;
			break;
		case 'r':
			grids[currentIndex][cursorX][cursorY] = !grids[currentIndex][cursorX][cursorY];
		default:
			break;
		}
	}
}


