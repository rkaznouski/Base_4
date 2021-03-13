#include <iostream>
using namespace std;

void printNumberFibonacciSequence(int numberInRow);

int main() {
	int numberInRow = 0;

	cout << "Hello, user! Let's find number in row of Fibonacci." << endl
		<< "Enter number in row: ";
	cin >> numberInRow;

	printNumberFibonacciSequence(numberInRow);

	return 0;
}

void printNumberFibonacciSequence(int numberInRow) {
	int firstNumber = 0, secondNumber = 1, nextNumber = 0, iterator = 3;

	if (numberInRow < 0) {
		cout << "ERROR. The number should be positive." << endl;
	}
	else if (numberInRow == 1) {
		cout << "The " << numberInRow << " number in row of Fibonacci is: " << firstNumber << endl;
	}
	else if (numberInRow == 2) {
		cout << "The " << numberInRow << " number in row of Fibonacci is: " << secondNumber << endl;
	}
	else {
		while (iterator <= numberInRow) {
			nextNumber = firstNumber + secondNumber;
			firstNumber = secondNumber;
			secondNumber = nextNumber;
			iterator++;
		}
		cout << "The " << numberInRow << " number in row of Fibonacci is: " << nextNumber << endl;
	}
}