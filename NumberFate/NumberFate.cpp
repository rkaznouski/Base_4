#include <iostream>
using namespace std;

bool isPositive(int birthDay, int birthMonth, int birthYear);
bool isMoreZero(int birthDay, int birthMonth, int birthYear);
int getNumberFate(int birthDay, int birthMonth, int birthYear);

int main() {
	int birthDay, birthMonth, birthYear = 0;

	cout << "Hello, user! Let's get your number of fate." << endl
		<< "Enter your day of birth: ";
	cin >> birthDay;
	cout << "Enter your month of birth: ";
	cin >> birthMonth;
	cout << "Enter your year of birth: ";
	cin >> birthYear;

	if (isPositive(birthDay, birthMonth, birthYear) and
		isMoreZero(birthDay, birthMonth, birthYear)) {
		
		cout << "Your number of fate is: " << getNumberFate(birthDay, birthMonth, birthYear) << endl;
		return 0;
	}
	else {
		cout << "ERROR. Value should be positive or more than zero." << endl;
		return 1;
	}
}

int getNumberFate(int birthDay, int birthMonth, int birthYear) {
	int numberFate = 0;
	int sum = birthDay + birthMonth + birthYear;

	while (sum != 0) {
		numberFate += sum % 10;
		sum /= 10;
	}

	while (numberFate > 9) {
		numberFate = (numberFate % 10) + (numberFate / 10);
	}
	return numberFate;
}

bool isMoreZero(int birthDay, int birthMonth, int birthYear) {
	if (birthDay == 0 or birthMonth == 0 or birthYear == 0) {
		return false;
	}
	return true;
}

bool isPositive(int birthDay, int birthMonth, int birthYear) {
	if (birthDay < 0 or birthMonth < 0 or birthYear < 0) {
		return false;
	}
	return true;
}