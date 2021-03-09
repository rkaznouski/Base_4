#include <iostream>
#include <windows.h>
using namespace std;

#define LENGTHCHESSBOARD 8
#define HORSEMOVES 8
#define N 64

struct coordinate {
	int X;
	int Y;
};

bool isCharactersCorrect(char arr);
int getNumberFromChar(char arr);
void createChessBoard(struct coordinate coordChessBoard[]);
void printChessBoard(struct coordinate chessBoard[]);
void searchChessMoves(struct coordinate coord, struct coordinate arr[]);
bool matchSearch(struct coordinate firstChessMoves[], struct coordinate secondHorseCoordinates);
void changeColour(int color);

int main() {
	struct coordinate coordChessBoard[N] = { 0 };
	struct coordinate firstHorseMoves[HORSEMOVES] = { 0 };
	struct coordinate firstCoordinate, secondCoordinate;
	char firstX, firstY, secondX, secondY;
	int numbFirstX, numbFirstY, numbSecondX, numbSecondY;

	createChessBoard(coordChessBoard);
	
	changeColour(14);
	cout << "\t\t[ * * * TWO CHESS KNIGHTS GAME * * * ]" << endl;
	changeColour(15);

	printChessBoard(coordChessBoard);
	
	cout << endl << "Hello, user!" << endl <<
		"Enter four numbers. The first pair of numbers is the coordinate of the first " << endl <<
		"knight. The second pair of numbers is the coordinates of the second knight." << endl <<
		"Then we will find out if they hit each other." << endl;
	
	cout << endl << "Enter the first pair of numbers: " << endl;
	cout << "Coordinate X: [from 1 to 8]" << endl;
	cin >> firstX;
	cout << "Coordinate Y: [from 1 to 8]" << endl;
	cin >> firstY;

	cout << endl << "Enter the second pair of numbers: " << endl;
	cout << "Coordinate X: [from 1 to 8]" << endl;
	cin >> secondX;
	cout << "Coordinate Y: [from 1 to 8]" << endl;
	cin >> secondY;
	

	if (isCharactersCorrect(firstX) && isCharactersCorrect(firstY) &&
		isCharactersCorrect(secondX) && isCharactersCorrect(secondY)) {
		numbFirstX = getNumberFromChar(firstX);
		numbFirstY = getNumberFromChar(firstY);
		numbSecondX = getNumberFromChar(secondX);
		numbSecondY = getNumberFromChar(secondY);
		
		firstCoordinate = { numbFirstX, numbFirstY };
		secondCoordinate = { numbSecondX, numbSecondY };

		searchChessMoves(firstCoordinate, firstHorseMoves);

		if (matchSearch(firstHorseMoves, secondCoordinate)) {
			changeColour(10);
			cout << endl << "Chess pieces beat each other!" << endl;
			changeColour(15);
		}
		else {
			changeColour(12);
			cout << endl << "Chess pieces don't beat each other." << endl;
			changeColour(15);
		}
		return 0;
	}
	return 1;
}

bool matchSearch(struct coordinate firstChessMoves[], struct coordinate secondHorseCoordinates) {
	int i = 0, j = 0;

	while (i < HORSEMOVES) {
		if (firstChessMoves[i].X == secondHorseCoordinates.X and firstChessMoves[i].Y == secondHorseCoordinates.Y) {
			return true;
		}
		i++;
	}
	return false;
}

void searchChessMoves(struct coordinate coord, struct coordinate arr[]) {
	int i = 0;
	
	arr[i].X = coord.X + 1;
	arr[i].Y = coord.Y - 2;
	i++;
	arr[i].X = coord.X + 2;
	arr[i].Y = coord.Y - 1;
	i++;
	arr[i].X = coord.X + 2;
	arr[i].Y = coord.Y + 1;
	i++;
	arr[i].X = coord.X + 1;
	arr[i].Y = coord.Y + 2;
	i++;
	arr[i].X = coord.X - 1; 
	arr[i].Y = coord.Y + 2;  
	i++;
	arr[i].X = coord.X - 2; 
	arr[i].Y = coord.Y + 1; 
	i++;
	arr[i].X = coord.X - 2;
	arr[i].Y = coord.Y - 1; 
	i++;
	arr[i].X = coord.X - 1;
	arr[i].Y = coord.Y - 2;
}

void printChessBoard(struct coordinate chessBoard[]) {
	int i = 0, j = 0;

	while(i < N) {
		while (j < LENGTHCHESSBOARD) {
			cout << "|| " << chessBoard[i].X << " . " << chessBoard[i].Y << " ";
			j++;
			i++;
		}
		cout << " ||";
		cout << endl;
		j = 0;
	}
}

void createChessBoard(struct coordinate coordChessBoard[]) {
	int i = 0, j = 0, row = 1, column = 1;

	while (i < N) {
		while (j < LENGTHCHESSBOARD) {
			coordChessBoard[i].X = column;
			coordChessBoard[i].Y = row;
			column++;
			j++;
			i++;
		}
		j = 0;
		row++;
		column = 1;
	}
}

bool isCharactersCorrect(char arr) {
	if (arr < '1' or arr > '8') {
		changeColour(12);
		cout << endl << "ERROR. Value should be from 1 to 8." << endl;
		changeColour(15);
		return false;
	}
	return true;
}

int getNumberFromChar(char arr) {
	int charToInt = 0;

	return charToInt = (int)arr - 48;
}

void changeColour(int colour) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, colour);
}