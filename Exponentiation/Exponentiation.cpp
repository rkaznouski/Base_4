#include <iostream>
using namespace std;

double getNumberInDegree(double userNumber, int degree);

int main() {
	double userNumber = 0;
	int degree = 0;

	cout << "Hello, user! Let's raise the number to the degree." << endl
		<< "Enter the number: ";
	cin >> userNumber;
	cout << "Enter the degree: ";
	cin >> degree;

	cout << "Number " << userNumber << " in " << degree << " degree is: " << getNumberInDegree(userNumber, degree) << endl;

	return 0;
}

double getNumberInDegree(double userNumber, int degree) {
	double baseNumber = userNumber;
	userNumber = 1;

	if (degree > 0) {
		for (int i = 0; i < degree; i++)
			userNumber *= baseNumber;
	}
	else if (degree < 0) {
		for (int i = 0; i > degree; i--)
			userNumber /= baseNumber;
	}
	else
		userNumber = 1;
	
	return userNumber;
}