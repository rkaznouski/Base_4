#include <iostream>
#include <Windows.h>
using namespace std;

#define DIGITS 5

void changeColour(int colour);
bool isCharactersCorrect(char arr[]);
int getNumberFromChar(char arr[]);
int getFactor(int degree);

int main() {
	char userNumber[DIGITS] = { 0 };
    int userIntNumber = rand() % 2000 + 1000, guessNumber = rand() % 1000 + 1, attempts = 0;

    changeColour(14);
    cout << "\t\t[ * * * GUESS THE NUMBER GAME * * * ]" << endl;
    changeColour(15);

    cout << "Hello, user! Let's play a game guess the number." << endl 
        << "I choosed a number from [ 1 to 1000 ] and you will try to guess it." << endl
        << "You will receive hints if the number is GREATER" << endl 
        << "or LESS than the required number." << endl;

    while (userIntNumber != guessNumber) {
        cout << "Enter your number:" << endl;
        cin.getline(userNumber, DIGITS);
        attempts++;
        if (isCharactersCorrect(userNumber)) {
            userIntNumber = getNumberFromChar(userNumber);
            if (userIntNumber < guessNumber) {
                cout << "Your number is less than guess number. Try enter another number." << endl;
                continue;
            }
            else if (userIntNumber > guessNumber) {
                cout << "Your number is more than guess number. Try enter another number." << endl;
                continue;
            }
        }
        else
            return 1;
    }
    cout << "Congratulations! It's really [ " << guessNumber << " ] " << endl
        << "You guessed the number on the " << attempts << " try." << endl;
    
    return 0;
}

bool isCharactersCorrect(char arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] < '0' or arr[i] > '9') {
            cout << "ERROR. Number should be positive and contain only numbers." << endl;
            return false;
        }
        i++;
    }
    return true;
}

int getNumberFromChar(char arr[]) {
    int i = 0, charToInt = 0, factor = 0, degree = 0, number = 0;
    while (arr[i] != '\0') {
        degree++;
        i++;
    }
    i = 0;

    factor = getFactor(degree - 1);

    while (arr[i] != '\0') {
        charToInt = arr[i] - 48;
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

void changeColour(int colour) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, colour);
}