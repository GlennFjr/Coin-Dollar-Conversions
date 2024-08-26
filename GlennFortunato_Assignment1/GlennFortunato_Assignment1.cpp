// Glenn Fortunato
// Assignment 1
// Converting a dollar amount into individual coin values, and vice-versa
// COP3014-001
// Professor Taebi
// Florida Atlantic University
// 9/8/2023


#include <iostream>
#include <cstdlib>
using namespace std;

void DollarsToCoins();
void CoinsToDollars();
void Continue();
int InputVerification();


int main()
{
    // Menu selection to choose which conversion.
    int menuSelect = 0;
    while(true){
        cout << endl << "Welcome to the Coin Dispensery Machine." << endl;
        cout << "---    -Please Select an Option-    ---" << endl << endl;
        cout << "1. Dollars -> Coins" << endl;
        cout << "2. Coins -> Dollars" << endl;
        cout << "3. Quit" << endl;

        cin >> menuSelect;

        // Input Verification
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Only numbers are accepted." << endl;
            cout << "Try again." << endl;
            cin >> menuSelect;
        }

        switch (menuSelect) {
         case 1:
             DollarsToCoins();
             break;
         case 2:
             CoinsToDollars();
             break;
         case 3:
             exit(1);
          default:
             cout << "Invalid Choice, Please Select 1, 2, or 3." << endl;
             continue;
        }

    }

    
}


void DollarsToCoins()
{
    // Declares variable and prompts for a dollar amount input.
    double inputAmount;
    cout << "Input dollar amount ($XX.XX): $";
    cin >> inputAmount;

    // Input Verification
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Only numbers are accepted." << endl;
        cout << "Try again." << endl;
        cin >> inputAmount;
    }


    // Aborts if input is negative
    if (inputAmount < 0) {
        cout << "Negative values are not accepted." << endl;
        exit(1);
    }

    // Aborts if amount is > $100
    if (inputAmount > 100) {
        cout << "Values greater than $100.00 are not accepted" << endl;
        exit(1);
    }

    // Declaring variables, using the US coin system as reference
    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;

    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int extraCents = 0;

    // Converts input to a cent amount
    int centAmount = inputAmount * 100;

    // Counts the number of quarters and leftover change
    if (centAmount >= 25) {
        quarters = centAmount / 25;
        centAmount = centAmount % 25;
    }

    // Counts the number of dimes and leftover change
    if (centAmount >= 10) {
        dimes = centAmount / 10;
        centAmount = centAmount % 10;
    }

    // Counts the number of nickels and leftover change
    if (centAmount >= 5) {
        nickels = centAmount / 5;
        centAmount = centAmount % 5;
    }

    // Counts the number of pennies leftover
    if (centAmount < 5) {
        pennies = centAmount;
    }

    // Converts change back into the previous total
    double total = (quarters * QUARTER) + (dimes * DIME) + (nickels * NICKEL) + (pennies * PENNY);
    total = total / 100;

    cout << endl << "Your amount in coins is: " << endl << quarters << " Quarters" << endl << dimes << " Dimes" << endl << nickels << " Nickels" << endl << pennies << " Pennies" << endl;
    cout << endl << "Original Amount: $" << total << endl << endl;

    Continue();
}


void CoinsToDollars()
{
    // Declaring variables, using the US coin system as reference.

    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;

    // Prompts user for each coin.
    cout << endl << "Enter an amount for each coin." << endl;
    cout << "Number of Quarters: ";
    cin >> quarters;
    if (cin.fail()) {
        quarters = InputVerification();
    }

    cout << "Number of Dimes: ";
    cin >> dimes;
    if (cin.fail()) {
        dimes = InputVerification();
    }

    cout << "Number of Nickels: ";
    cin >> nickels;
    if (cin.fail()) {
        nickels = InputVerification();
    }

    cout << "Number of Pennies: ";
    cin >> pennies;
    if (cin.fail()) {
        pennies = InputVerification();
    }

    // Declares and calculates total amount
    int total;

    total = (quarters * QUARTER) + (dimes * DIME) + (nickels * NICKEL) + (pennies * PENNY);

    int dollars = total / 100;
    int cents = total % 100;

    cout << endl << "Your coins are equal to $" << dollars << "." << cents << endl;

    Continue();

    
}


void Continue() {
    // 
    cout << endl << "Would you like to continue with another conversion?";
    cout << endl << "1. Continue" << endl << "2. Quit" << endl;
    int userInput;
    
    // Input Verification
    cin >> userInput;

    if (cin.fail())
    {
        InputVerification();
    }

    while (true) {
        switch (userInput) {
        case 1:
            break;
        case 2:
            exit(1);
            break;
        default:
            cout << "Invalid Choice, Please Select 1, 2, or 3." << endl;
            continue;
        }
        break;
    }
        
}


int InputVerification() {
    // Input Verification
    int input;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Only numbers are accepted." << endl;
        cout << "Try again." << endl;
        cin >> input;
    }
    return input;
}
