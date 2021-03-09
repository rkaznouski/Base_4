#include <iostream>
using namespace std;

#define DIGITS 9

int getNumberFromChar(char arr[]);
bool isCharactersCorrect(char arr[]);

int main() {
    char userNumber[DIGITS] = {0};
    
    cout << "Hello, user! Enter a fractional real number." << endl
        << " I will find and send the first digit of the fractional part to the output stream." << endl
        << "Enter your number [max 8 digits]: " << endl;
    cin.getline(userNumber, DIGITS);

    if (isCharactersCorrect(userNumber)) {
        cout << "The first digit of the fractional part is: " << getNumberFromChar(userNumber) << endl;
        return 0;
    }
	return 1;
}

bool isCharactersCorrect(char arr[]) {
    int i = 0, dotCounter = 0;

    while (arr[i] != '\0') {
        if (arr[i] == '.') {
            dotCounter++;
            i++;
        }
        if (dotCounter > 1) {
            cout << "ERROR. The real fractional number should contain only one dot." << endl;
            return false;
        }
        if (arr[i] < '0' or arr[i] > '9') {
            cout << "ERROR. Number should be positive and contain only numbers." << endl;
            return false;
        }
        i++;
    }
    if (dotCounter == 0) {
        cout << "ERROR. The real fractional number should contain fractional part." << endl;
        return false;
    }
    return true;
}

int getNumberFromChar(char arr[]) {
    int i = 0, charToInt = 0;
    while (arr[i] != '.') {
        i++;
    }
    return charToInt = arr[i + 1] - 48;
}