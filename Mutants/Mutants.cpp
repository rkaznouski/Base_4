#include <iostream>
#include <windows.h>
using namespace std;

#define N 6

void changeColour(int colour);
bool isCharactersCorrect(char arr[]);
int getNumberFromChar(char arr[]);
int getFactor(int degree);
int getQuantityReproduction(double countZombies, double percentReproduction);
int getDaysToDestroy(int intQuantityMutants, int mutantReproduction, int mutantDestruction);

int main() {
	char quantityMutants[N] = { 0 }, percentReproduction[N] = { 0 }, quantityDestruction[N] = { 0 };
	int daysToFullDestroy = 0, intQuantityMutants = 0, intPercentReproduction = 0, intQuantityDestruction = 0;

	changeColour(12);
	cout << "[ _ _ _ _ BREAK NEWS _ _ _ _ ]" << endl
		<< "Minsk was attacked by MUTANTS!!!" << endl;
	changeColour(15);

	cout << endl << "How many mutants have attacked Minsk?" << endl;
	cin.getline(quantityMutants, N);
	if (isCharactersCorrect(quantityMutants)) {
		intQuantityMutants = getNumberFromChar(quantityMutants);
		
		cout << "What is the increase in mutants per day (percent)?" << endl;
		cin.getline(percentReproduction, N);
		if (isCharactersCorrect(percentReproduction)) {
			intPercentReproduction = getNumberFromChar(percentReproduction);

			cout << "With each day the increase will be (mutants): " << endl
				<< getQuantityReproduction(intQuantityMutants, intPercentReproduction) << endl;

			cout << "How many mutants are destroyed by utilities every day?" << endl;
			cin.getline(quantityDestruction, N);
			if (isCharactersCorrect(quantityDestruction)) {
				intQuantityDestruction = getNumberFromChar(quantityDestruction);

				if (getQuantityReproduction(intQuantityMutants, intPercentReproduction) > intQuantityDestruction) {
					changeColour(12);
					cout << endl << "This is a catastrophe! We will not be able to resist so many mutants!" << endl;
					changeColour(15);
				}
				else {
					changeColour(10);
					cout << endl << "All mutants will be destroyed after a number of days: " <<
						getDaysToDestroy(intQuantityMutants,
							getQuantityReproduction(intQuantityMutants, intPercentReproduction),
							intQuantityDestruction) << endl;
					changeColour(15);
				}
				return 0;
			}
		}
	}
	return 1;
}

int getDaysToDestroy(int intQuantityMutants, int mutantReproduction, int mutantDestruction) {
	return intQuantityMutants / (mutantDestruction - mutantReproduction);
}

bool isCharactersCorrect(char arr[]) {
	int i = 0;

	while (arr[i] != '\0') {
		if (arr[i] < '0' or arr[i] > '9') {
			cout << "ERROR. Value should be greater than or equal to zero and contain only numbers." << endl;
			return false;
		}
		i++;
	}
	return true;
}

int getNumberFromChar(char arr[]) {
	int i = 0, charToInt = 0, degree = 0, factor = 0, number = 0;

	while (arr[i] != '\0') {
		degree++;
		i++;
	}
	i = 0;

	factor = getFactor(degree - 1);

	while (arr[i] != '\0') {
		charToInt = (int)arr[i] - 48;
		number += charToInt * factor;
		factor /= 10;
		i++;
	}
	return number;
}

int getFactor(int degree) {
	int factor = 1;
	while (degree != 0) {
		factor *= 10;
		degree--;
	}
	return factor;
}

int getQuantityReproduction(double countZombies, double percentReproduction) {
	return countZombies * (percentReproduction / 100);
}

void changeColour(int colour) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, colour);
}