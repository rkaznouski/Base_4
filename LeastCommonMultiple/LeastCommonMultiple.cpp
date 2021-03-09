#include <iostream>
using namespace std;

#define NUMBERLENGTH 9

bool isCharactersCorrect(char arr[]);
int getNumberFromChar(char arr[]);
int getFactor(int degree);
int getLeastCommonMultiple(int firstIntNumber, int secondIntNumber);
bool isPrime(int number);

int main()
{
    char firstCharNumber[NUMBERLENGTH] = { 0 }, secondCharNumber[NUMBERLENGTH] = { 0 };
    int firstIntNumber, secondIntNumber;

    cout << "Hello, user! Let's find the smallest common divisor of two numbers." << endl
        << "Enter first number [not more than 8 digits]:" << endl;
    cin.getline(firstCharNumber, 9);
    cout << "Enter second number [not more than 8 digits]:" << endl;
    cin.getline(secondCharNumber, 9);

    if (isCharactersCorrect(firstCharNumber)){
        if(isCharactersCorrect(secondCharNumber)){
            firstIntNumber = getNumberFromChar(firstCharNumber);
            secondIntNumber = getNumberFromChar(secondCharNumber);

            if (firstIntNumber == 0 or secondIntNumber == 0) {
                cout << "ERROR. Numbers should be positive." << endl;
                return 1;
            }
            else {
                cout << "The least common multiple number of " << firstIntNumber <<
                    " and " << secondIntNumber << " is: " << endl
                    << getLeastCommonMultiple(firstIntNumber, secondIntNumber) << endl;
            }
            return 0;
        }
    }
    return 1;
}

int getLeastCommonMultiple(int firstIntNumber, int secondIntNumber) {
    int temp = 0;
    if (isPrime(firstIntNumber) and isPrime(secondIntNumber)) {
        return firstIntNumber * secondIntNumber;
    }
    else if (firstIntNumber < secondIntNumber) {
        temp = firstIntNumber;
        while (firstIntNumber % secondIntNumber != 0) {
            firstIntNumber += temp;
        }
        return firstIntNumber;
    }
    else if (firstIntNumber > secondIntNumber) {
        temp = secondIntNumber;
        while (secondIntNumber % firstIntNumber != 0) {
            secondIntNumber += temp;
        }
        return secondIntNumber;
    }
    else {
        return firstIntNumber;
    }
}

bool isPrime(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

bool isCharactersCorrect(char arr[]){
    int i = 0;
    while(arr[i] != '\0'){
        if(arr[i] < '0' or arr[i] > '9'){
            cout << "ERROR. Number should be positive and contain only numbers." << endl;
            return false;
        }
        i++;
    }
    return true;
}

int getNumberFromChar(char arr[]){
    int i = 0, charToInt = 0, factor = 0, degree = 0, number = 0;
    while(arr[i] != '\0'){
        degree++;
        i++;
    }
    i = 0;

    factor = getFactor(degree - 1);

    while(arr[i] != '\0'){
        charToInt = arr[i] - 48;
        number += charToInt * factor;
        factor /= 10;
        i++;
    }
    return number;
}

int getFactor(int degree){
    int factor = 1;
    while(degree != 0){
        factor *= 10;
        degree--;
    }
    return factor;
}
