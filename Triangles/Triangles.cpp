#include <iostream>
using namespace std;

#define SIDESOFTRIANGLE 3
#define DIGITS 6

bool isCharactersCorrect(char arr[]);
int getNumberFromChar(char arr[]);
int getFactor(int degree);
void printTypeTriangle(int firstSide, int secondSide, int thirdSide);
bool triangleExist(int firstSide, int secondSide, int thirdSide);
int getMaxSide(int firstSide, int secondSide, int thirdSide);
int getMinSide(int firstSide, int secondSide, int thirdSide);
int getMiddleSide(int firstSide, int secondSide, int thirdSide);

int main() {
    char firstSide[DIGITS], secondSide[DIGITS], thirdSide[DIGITS];
    int numbFirstSide = 0, numbSecondSide = 0, numbThirdSide = 0;

    cout << "Hello, user! Enter the three lengths of the sides of the triangle." << endl
        << "I will determine the type of triangle." << endl
        << "Enter the first length of the side: [max 5 digits]" << endl;
    cin.getline(firstSide, DIGITS);

    cout << "Enter the second length of the side: [max 5 digits]" << endl;
    cin.getline(secondSide, DIGITS);

    cout << "Enter the third length of the side: [max 5 digits]" << endl;
    cin.getline(thirdSide, DIGITS);

    if (isCharactersCorrect(firstSide)) {
        if (isCharactersCorrect(secondSide)) {
            if (isCharactersCorrect(thirdSide)) {
                numbFirstSide = getNumberFromChar(firstSide);
                numbSecondSide = getNumberFromChar(secondSide);
                numbThirdSide = getNumberFromChar(thirdSide);

                if (triangleExist(numbFirstSide, numbSecondSide, numbThirdSide)) {
                    printTypeTriangle(numbFirstSide, numbSecondSide, numbThirdSide);
                }
                else
                    cout << "The triangle doesn't exist." << endl;
                return 0;
            }
        }
    }
	return 1;
}

void printTypeTriangle(int firstSide, int secondSide, int thirdSide) {
    int maxSide = getMaxSide(firstSide, secondSide, thirdSide);
    int minSide = getMinSide(firstSide, secondSide, thirdSide);
    int middleSide = getMiddleSide(firstSide, secondSide, thirdSide);
    
    if (firstSide == secondSide == thirdSide)
        cout << "It is the equilateral triangle." << endl;
    else if (firstSide == secondSide or secondSide == thirdSide or firstSide == thirdSide)
        cout << "It is isosceles triangle." << endl;
    else if ((maxSide * maxSide) == (middleSide * middleSide) + (minSide * minSide))
        cout << "It is right triangle." << endl;
    else
        cout << "It is general triangle." << endl;
}

bool triangleExist(int firstSide, int secondSide, int thirdSide) {
    int maxSide = getMaxSide(firstSide, secondSide, thirdSide);
    int minSide = getMinSide(firstSide, secondSide, thirdSide);
    int middleSide = getMiddleSide(firstSide, secondSide, thirdSide);

    if (maxSide < middleSide + minSide)
        return true;
    else
        return false;
}

int getMaxSide(int firstSide, int secondSide, int thirdSide) {
    int max = firstSide;
    if (secondSide > firstSide) max = secondSide;
    if (thirdSide > firstSide) max = thirdSide;
    return max;
}

int getMinSide(int firstSide, int secondSide, int thirdSide) {
    int min = firstSide;
    if (secondSide < firstSide) min = secondSide;
    if (thirdSide < firstSide) min = thirdSide;
    return min;
}

int getMiddleSide(int firstSide, int secondSide, int thirdSide) {
    if (secondSide < firstSide and firstSide < thirdSide)
        return firstSide;
    else if (secondSide > firstSide and secondSide < thirdSide)
        return secondSide;
    else
        return thirdSide;
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