#include <iostream>
#include <windows.h>

using namespace std;

#define PIN 9012
#define MAX_BALANCE 5000
#define MAX_CUPS 700
#define MAX_BANKNOTE 500
#define MIN_COIN 0.5
#define ESPRESSO_PRICE 2.0
#define CAPUCHINO_PRICE 2.5
#define LATTE_PRICE 3.0

struct serviceData {
    double userBalance;
    double balanceCoffeeMachine;
    int cups;
    int authentificationAttempts;
};

// Main menu functions 
bool isInitCorrectCoffeeBox(serviceData& variableValues);
void printMainMenu(serviceData& variableValues);
double inputUserNumber(double value);
bool isInputValueCorrect(double value, double startValue, double endValue);
bool isMultiplicityCorrect(double value);
void printUserBalans(serviceData& variableValues);
void inputUserMoney(serviceData& variableValues);

// Coffee menu functions
void printMenuCoffee(serviceData& variableValues);
bool isCupsExist(serviceData& variableValues);
void selectCoffee(serviceData& variableValues);
int cookCoffee(serviceData& variableValues, string nameCoffee, double price);
bool checkConditionsMakingCoffee(serviceData& variableValues, double price);
bool isEnoughMoney(serviceData& variableValues, double price);
bool isEnoughCups(serviceData& variableValues);
void showProcessCookCoffee(string nameCoffee);

// Service menu functions
int selectServiceMenu(serviceData& variableValues);
void printServiceMenu(serviceData& variableValues);
void showCurrentBalance(serviceData& variableValues);
void showNumberCupsRemaining(serviceData& variableValues);
void takeMoney(serviceData& variableValues);
void refillCups(serviceData& variableValues);
int autentification(serviceData& variableValues);

// Visualisation functions
void clearDisplay();
void showErrorMessage(string message);
void showSuccessfulMessage(string message);
void changeColour(int colour);
void printTitle();
void printTitleServiceMenu();
void blockCoffeeMachine();
void exitProgram();

int main() {
    // The first number - user balance
    // The second number - coffee box balance
    // The third number - count cups
    // The fourth number - authentication attempts
    serviceData variableValues = { 0.0, 0.0, 7, 0 };
    double userChoice = 0;

    while (true) {
        if (isInitCorrectCoffeeBox(variableValues)) {       // Checking cups and overflow balance
            printMainMenu(variableValues);

            userChoice = inputUserNumber(userChoice);
            if (!isInputValueCorrect(userChoice, 1, 3))
                continue;

            if (userChoice == 1)
                inputUserMoney(variableValues);
            else if (userChoice == 2)
                selectCoffee(variableValues);
            else if (userChoice == 3)
                selectServiceMenu(variableValues);
        }
        else
            break;
    }
}

bool isInitCorrectCoffeeBox(serviceData& variableValues) {
    if (variableValues.cups == 0) {
        showErrorMessage("Error! The coffee machine has run out of cups.");
        return false;
    }
    if (variableValues.cups <= 5) {
        changeColour(12);
        cout << "WARNING. Coffee machine contain " << variableValues.cups << " cups." << endl;
        changeColour(15);
        return true;
    }
    else if (variableValues.userBalance >= MAX_BALANCE) {
        showErrorMessage("Error! The coffee machine cannot accept money.");
        return false;
    }
    return true;
}

void printMainMenu(serviceData& variableValues) {
    printTitle();
    printUserBalans(variableValues);

    changeColour(2);
    cout << endl << "[ ===>  USER'S GUIDE:  <=== ]";
    changeColour(15);
    cout << endl << "To get our great coffee, select "; changeColour(2); cout << "[ 1 ]"; changeColour(15);
    cout << endl << "and deposit the required amount." << endl;
    changeColour(12);
    cout << endl << "PLEASE NOTE, COFFEE MACHINE:" << endl
        << " * DOESN'T RETURN CHANGE" << endl
        << " * DOESN'T accept coins lower than 0.50 BYN" << endl
        << " * DOESN'T accept banknotes highter than 100 BYN " << endl;
    changeColour(15);
    cout << endl << "Then, to select the type of coffee, select "; changeColour(2); cout << "[ 2 ]"; changeColour(15);
    cout << endl << "For service, select "; changeColour(2); cout << "[ 3 ]" << endl;
    changeColour(2); cout << endl << "[ 1 ]"; changeColour(15); cout << " Put money." << endl;
    changeColour(2); cout << "[ 2 ]"; changeColour(15); cout << " Select coffee." << endl;
    changeColour(2); cout << "[ 3 ]"; changeColour(15); cout << " Service menu." << endl;
    cout << "Your choice? " << endl;
}

void printTitle() {
    changeColour(14);
    cout << "[= = = = = = = = = = = = = = = =]" << endl;
    cout << "[ * * * ESPRESSO BIANCCI  * * * ]" << endl;
    cout << "[  * TASTE * AROMA * PLEASURE * ]" << endl;
    cout << "[= = = = = = = = = = = = = = = =]" << endl;
    changeColour(15);
}

void printUserBalans(serviceData& variableValues) {
    changeColour(11);
    if (variableValues.userBalance < 10)
        cout << "     ";
    else if (variableValues.userBalance > 10 and variableValues.userBalance < 100)
        cout << "    ";
    else if (variableValues.userBalance > 100)
        cout << "   ";
    cout << "Your balance is: " << variableValues.userBalance << " BYN" << endl;
    changeColour(15);
}

void inputUserMoney(serviceData& variableValues) {
    clearDisplay();

    if (isCupsExist(variableValues)) {
        cout << "Put money: ";
        double changeBalance = 0;
        changeBalance = inputUserNumber(changeBalance);

        if (isInputValueCorrect(changeBalance, MIN_COIN, MAX_BANKNOTE)) {
            variableValues.userBalance += changeBalance;
            clearDisplay();

            changeColour(10);
            cout << "Your money has been successfully credited: "
                << changeBalance << " BYN." << endl;
            changeColour(15);
        }
    }
}

void clearDisplay() {
    system("cls");
}

bool isCupsExist(serviceData& variableValues) {
    if (variableValues.cups <= 5) {
        changeColour(12);
        cout << "WARNING. Coffee machine contain " << variableValues.cups << " cups." << endl;
        changeColour(15);
        return true;
    }
    else if (variableValues.cups > 0) {
        return true;
    }
    else {
        showErrorMessage("Error! Sorry, we cannot accept money and fulfill your order because the cups have run out.");
        return false;
    }
}

void showSuccessfulMessage(string message) {
    changeColour(10);
    cout << message << endl;
    changeColour(15);
}

void showErrorMessage(string message) {
    changeColour(12);
    cout << message << endl;
    changeColour(15);
}

void selectCoffee(serviceData& variableValues) {
    clearDisplay();
    printTitle();
    double userChoice = 0;

    while (true) {
        printMenuCoffee(variableValues);

        userChoice = inputUserNumber(userChoice);
        if (!isInputValueCorrect(userChoice, 1, 4))
            continue;

        if (userChoice == 1)
            cookCoffee(variableValues, "Expresso", ESPRESSO_PRICE);
        else if (userChoice == 2)
            cookCoffee(variableValues, "Cappuccino", CAPUCHINO_PRICE);
        else if (userChoice == 3)
            cookCoffee(variableValues, "Latte", LATTE_PRICE);
        else if (userChoice == 4)
            break;
    }
    clearDisplay();
}

void printMenuCoffee(serviceData& variableValues) {
    printUserBalans(variableValues);

    cout << endl << "What do you prefer?";
    changeColour(2); cout << endl << "[ 1 ]"; changeColour(15); cout << " If you have a momentary need for caffeine, try our espresso." <<
        endl << "It is a coffee drink characterized by a small volume," <<
        endl << "strong and made from finely ground beans under high water pressure." << endl;
    changeColour(2); cout << endl << "[ 2 ]"; changeColour(15); cout << " If you would like to enjoy a great tasting coffee, choose our cappuccino." <<
        endl << "Espresso coffee with heated frothed milk. A thick layer of thick, creamy foam," <<
        endl << "accompanied by a sweetish warming milk and a rich taste of well-brewed espresso." << endl;
    changeColour(2); cout << endl << "[ 3 ]"; changeColour(15); cout << " If you want a light coffee and creamy taste, try our latte." <<
        endl << "The largest and mildest espresso-based coffee drink." <<
        endl << "Suitable for those who do not like the bright taste of coffee." << endl;

    changeColour(2); cout << endl << "[ 1 ]"; changeColour(15); cout << " Expresso - "; changeColour(11); cout << ESPRESSO_PRICE << " BYN" << endl;
    changeColour(2); cout << "[ 2 ]"; changeColour(15); cout << " Cappuccino - "; changeColour(11); cout << CAPUCHINO_PRICE << " BYN" << endl;
    changeColour(2); cout << "[ 3 ]"; changeColour(15); cout << " Latte - "; changeColour(11); cout << LATTE_PRICE << " BYN" << endl;
    changeColour(2); cout << "[ 4 ]"; changeColour(15); cout << " Back to main menu." << endl;
    changeColour(15);
    cout << "Your choice? " << endl;
}

int cookCoffee(serviceData& variableValues, string nameCoffee, double price) {
    clearDisplay();

    if (!checkConditionsMakingCoffee(variableValues, price))
        return 1;
    else {
        showProcessCookCoffee(nameCoffee);

        showSuccessfulMessage(nameCoffee + " is ready. Enjoy your coffee!");
        variableValues.userBalance -= price;
        variableValues.balanceCoffeeMachine += price;
        variableValues.cups = variableValues.cups - 1;
        return 0;
    }
}

void showProcessCookCoffee(string nameCoffee) {
    int i = 0;
    string strProgress = "";

    changeColour(11);
    while (i < 51) {
        Sleep(10);
        clearDisplay();
        cout << "--------------------------------------------------" << endl;
        cout << "    We cook your aromatic coffee, please wait          " << endl;
        cout << "                        " << i * 2 << " %                         " << endl;
        cout << strProgress << endl;
        cout << "                                                  " << endl;
        cout << "                                                  " << endl;
        cout << "--------------------------------------------------" << endl;
        strProgress = strProgress + "*";
        i++;
    }
    changeColour(15);
    Sleep(1000);
    clearDisplay();
}

bool checkConditionsMakingCoffee(serviceData& variableValues, double price) {
    if (!isEnoughMoney(variableValues, price)) {
        showErrorMessage("Error! Not enough money to order.");
        return false;
    }
    if (!isEnoughCups(variableValues)) {
        showErrorMessage("Error! We cannot fulfill your order because we ran out of cups.");
        return false;
    }
    else
        return true;
}

bool isEnoughMoney(serviceData& variableValues, double price) {
    if (variableValues.userBalance < price)
        return false;
    return true;
}

bool isEnoughCups(serviceData& variableValues) {
    if (variableValues.cups == 0)
        return false;
    return true;
}

int selectServiceMenu(serviceData& variableValues) {
    int resultAu = autentification(variableValues);

    if (resultAu != 0)
        return resultAu;
    else
        clearDisplay();

    double userChoice = 0;

    while (true) {
        printServiceMenu(variableValues);

        userChoice = inputUserNumber(userChoice);
        if (!isInputValueCorrect(userChoice, 1, 6))
            continue;

        if (userChoice == 1)
            showCurrentBalance(variableValues);
        else if (userChoice == 2)
            showNumberCupsRemaining(variableValues);
        else if (userChoice == 3)
            refillCups(variableValues);
        else if (userChoice == 4)
            takeMoney(variableValues);
        else if (userChoice == 5)
            exitProgram();
        else if (userChoice == 6)
            break;
    }
    clearDisplay();

    return 0;
}

void exitProgram() {
    clearDisplay();
    exit(0);
}

int autentification(serviceData& variableValues) {
    clearDisplay();

    int userPin = 0;
    cout << endl << "Please, enter your PIN: ";
    cin >> userPin;

    if (userPin == PIN)
        return 0;
    else {
        variableValues.authentificationAttempts++;

        if (variableValues.authentificationAttempts == 3)
            blockCoffeeMachine();

        clearDisplay();
        showErrorMessage("Error! Your PIN is not valid.");

        return 1;
    }
}

void printServiceMenu(serviceData& variableValues) {
    printTitleServiceMenu();
    cout << endl << "To check funds in the bill acceptor, click "; changeColour(2); cout << "[ 1 ]"; changeColour(15);
    cout << endl << "To check the number of cups, click "; changeColour(2); cout << "[ 2 ]"; changeColour(15);
    cout << endl << "To refill the number of cups, click "; changeColour(2); cout << "[ 3 ]"; changeColour(15);
    cout << endl << "For withdrawing funds from the bill acceptor, click "; changeColour(2); cout << "[ 4 ] "; changeColour(15);
    cout << endl << "To switch off the coffee machine, click "; changeColour(2); cout << "[ 5 ]"; changeColour(15);
    cout << endl << "To exit the service menu, click "; changeColour(2); cout << "[ 6 ]" << endl; changeColour(15);

    changeColour(2); cout << "[ 1 ]"; changeColour(15); cout << " Check funds." << endl;
    changeColour(2); cout << "[ 2 ]"; changeColour(15); cout << " Check the number of cups." << endl;
    changeColour(2); cout << "[ 3 ]"; changeColour(15); cout << " Refill the number of cups." << endl;
    changeColour(2); cout << "[ 4 ]"; changeColour(15); cout << " Withdrawal of proceeds." << endl;
    changeColour(2); cout << "[ 5 ]"; changeColour(15); cout << " Switch of coffee machine." << endl;
    changeColour(2); cout << "[ 6 ]"; changeColour(15); cout << " Exit." << endl;
    cout << "Your choice? ";
}

void printTitleServiceMenu() {
    changeColour(14);
    cout << "[= = = = = = = = = = = = = = = =]" << endl;
    cout << "[ * * * ESPRESSO BIANCCI  * * * ]" << endl;
    cout << "[ * * * * SERVICE MENU * * * *  ]" << endl;
    cout << "[= = = = = = = = = = = = = = = =]" << endl;
    changeColour(15);
}

void showCurrentBalance(serviceData& variableValues) {
    clearDisplay();
    changeColour(11);
    cout << endl << "Unrealized funds: " << variableValues.userBalance;
    cout << endl << "Total money in the bill acceptor: " << variableValues.balanceCoffeeMachine + variableValues.userBalance << endl;
}

void showNumberCupsRemaining(serviceData& variableValues) {
    clearDisplay();
    changeColour(11);
    cout << endl << "Cups remaining: " << variableValues.cups << endl;
}

void takeMoney(serviceData& variableValues) {
    clearDisplay();
    changeColour(11);
    cout << endl << "Was withdrawn from the bill acceptor: " << variableValues.balanceCoffeeMachine + variableValues.userBalance << " BYN." << endl;
    variableValues.userBalance = variableValues.balanceCoffeeMachine = 0;
}

void refillCups(serviceData& variableValues) {
    double numberOfCups = 0;
    
    clearDisplay();
    changeColour(11);
    cout << "Cups remaining: " << variableValues.cups << endl;
    cout << "Max number of cups: " << MAX_CUPS << endl << endl;
    cout << "Refill number of cups by: ";

    numberOfCups = inputUserNumber(numberOfCups);

    if (isInputValueCorrect(numberOfCups, 0, MAX_CUPS - variableValues.cups)) {
        variableValues.cups += numberOfCups;
    }
}

void changeColour(int colour) {
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole, colour);
}

bool isInputValueCorrect(double value, double startValue, double endValue) {
    if (value >= startValue and value <= endValue
        and (isMultiplicityCorrect(value))) {               // Check input limit
        return true;
    }
    else if (!cin) {                                        // If user input incorrect value in cin function
        cin.clear();                                        // Clear error
        cin.ignore(10000, '\n');                            // Clear buffer
        clearDisplay();                                     // Clear display

        showErrorMessage("Error! You have entered incorrect data. Read the instructions carefully.");
        return false;
    }
    else {
        clearDisplay();
        showErrorMessage("Error! You have entered incorrect data. Read the instructions carefully.");
        return false;
    }
}

bool isMultiplicityCorrect(double value) {
    double remainder = 0;
    int temp = (int)value;

    remainder = value - temp;
    if (remainder == 0)
        return true;
    else if (remainder < MIN_COIN or remainder > MIN_COIN)
        return false;
    else
        return true;
}

double inputUserNumber(double value) {
    cin >> value;
    return value;
}

void blockCoffeeMachine() {
    clearDisplay();
    printTitle();
    changeColour(12);
    cout << endl << "Oops. The coffee machine is blocked. You entered the code incorrectly three times. Contact Support.";
    while (true) {};
}
