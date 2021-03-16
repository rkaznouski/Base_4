#include <iostream>
using namespace std;

int getFactor(int number);
int getInvertNumber(int number, int factor);

int main() {
	int userNumber = 0;

	cout << "Hello, user! Let's invert the number." << endl
		<< "Enter your number: ";
	cin >> userNumber;

	if (userNumber < 0 or userNumber == 0) {
		cout << "ERROR. Number should be positive or more than zero." << endl;
		return 1;
	}
	else if (userNumber < 10) {
		cout << "ERROR. One digit not invert." << endl;
		return 1;
	}
	else {
		cout << "Invert of your number is: ";
		cout << getInvertNumber(userNumber, getFactor(userNumber)) << endl;
		return 0;
	}
}

int getFactor(int number) {
	int factor = 1;

	while (number != 0) {
		factor *= 10;
		number /= 10;
	}
	return factor / 10;
}

int getInvertNumber(int number, int factor) {
	int invertNumber = 0;

	while (number % 10 == 0) {
		cout << 0;
		number /= 10;
		factor /= 10;
	}
	while (number > 0) {
		invertNumber += (number % 10) * factor;
		factor /= 10;
		number /= 10;
	}
	return invertNumber;
}