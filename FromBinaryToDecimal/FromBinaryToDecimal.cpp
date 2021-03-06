#include <iostream>
using namespace std;

#define N 10

bool isCharactersCorrect(char arr[]);
int getBinNumberFromChar(char arr[]);
int getFactor(int number);
int getDegreesOfTwo(int degree);

int main() {
	char binNumber[N] = { 0 };
	int intBinNumber = 0;

	cout << "Hello, user! Let's convert the number from binary to decimal." << endl
		<< "Enter your binary number [ no more than nine digits ]: " << endl;
	cin.getline(binNumber, N);

	if (isCharactersCorrect(binNumber)) {
		cout << "Your number in decimal notation: " << endl
			<< getBinNumberFromChar(binNumber) << endl;
		return 0;
	}
	return 1;
}

bool isCharactersCorrect(char arr[]) {
	int i = 0;

	while (arr[i] != '\0') {
		if (arr[i] < '0' or arr[i] > '1') {
			cout << "ERROR. Value should be consist the ones or zeros." << endl;
			return false;
		}
		i++;
	}
	return true;
}

int getBinNumberFromChar(char arr[]) {
	int i = 0, charToInt = 0, degree = 0, number = 0;

	while (arr[i] != '\0') {
		degree++;
		i++;
	}
	i = 0;
	degree--;
	
	while (arr[i] != '\0') {
		charToInt = arr[i] - 48;
		number += charToInt * getDegreesOfTwo(degree);
		i++;
		degree--;
	}
	return number;
}

int getDegreesOfTwo(int degree) {
	int number = 1;
	while (degree != 0) {
		number *= 2;
		degree--;
	}
	return number;
}