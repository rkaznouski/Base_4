#include <iostream>
using namespace std;

int getBinaryFromDecimal(int decNumber);
void printBinaryOnlyOnes(int decNumber);

int main() {
	int userNumber = 0;

	cout << "Hello, user! Let's find numbers in a sequence consisting only of ones." << endl
		<< "I will print all numbers that have only ones in binary." << endl
		<< "Enter your decimal number: " << endl;
	cin >> userNumber;

	if (userNumber < 1) {
		cout << "ERROR. Natural number should be positive." << endl;
		return 1;
	}
	else
		printBinaryOnlyOnes(userNumber);

	return 0;
}

void printBinaryOnlyOnes(int decNumber) {
	bool flag = false;
	for (int i = 1; i <= decNumber; i++) {
		int number = i;
		while (number > 0) {
			if (number % 2 == 1) {
				number /= 2;
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Number " << i << " consist only ones in binary notation: " << getBinaryFromDecimal(i) << endl;
	}
}

int getBinaryFromDecimal(int decNumber) {
	int binNumber = 0, remainder = 0, factor = 1;
	
	while (decNumber != 0) {
		remainder = decNumber % 2;
		binNumber += remainder * factor;
		factor *= 10;
		decNumber /= 2;
	}
	return binNumber;
}