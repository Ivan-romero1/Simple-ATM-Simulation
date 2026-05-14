#include <iostream>
#include <limits>
#include <string>
#include "UserAccount.h"

using namespace std;

void showMenu(){

    cout << "\nWelcome to the ATM App" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Please choose from the following options: " << endl; 
    cout << " 1. Check Balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " 4. Exit " << endl;
    cout << "-------------------------------------------" << endl; 
}

void clearBadInput(){

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void deposit(UserAccount& accountToDepositInto){

    double amountToDeposit;

    cout << "Please enter the amount that you want to deposit into the account: " << endl;
    cout << "Enter the amount in the following format: 25.00 or 100.00 or 1000.00 or 10000.00, etc" << endl;
    cout << "$";

    cin >> amountToDeposit;

    if(cin.fail()){

        clearBadInput();
        cout << "Invalid amount!" << endl;
        return;
    }

    if(amountToDeposit < 0){

        cout << "You cannot deposit negative amounts!" << endl;
        return;
    }

    double currentBalance = accountToDepositInto.getBalance();
    double newBalance = currentBalance + amountToDeposit;

    accountToDepositInto.setBalanceTo(newBalance);

    cout << "Your new Balance is: $" << accountToDepositInto.getBalance() << endl;
}

void withdraw(UserAccount& accountToWithdrawFrom){

    double amountToWithdraw;

    cout << "Please enter the amount you want to withdraw from the account: " << endl;
    cout << "\n" << endl;

    cin >> amountToWithdraw;

    if(cin.fail()){

        clearBadInput();
        cout << "Invalid amount!" << endl;
        return;
    }

    if(amountToWithdraw < 0){

        cout << "You cannot withdraw negative amounts!" << endl;
        return;
    }

    double currentBalance = accountToWithdrawFrom.getBalance();

    if(amountToWithdraw > currentBalance){

        cout << "\nInsufficient Funds for this amount." << endl;
        return;
    }

    double newBalance;

    newBalance = currentBalance - amountToWithdraw;

    accountToWithdrawFrom.setBalanceTo(newBalance);

    cout << "\nYour new Balance is: $" << accountToWithdrawFrom.getBalance() << endl;
}

int main(){

    UserAccount user1;

    string userNameInput;

    cout << "Please enter your account name: ";
    getline(cin, userNameInput);

    user1.setNameTo(userNameInput);

    bool stillRunning = true;

    while(stillRunning){

        showMenu();

        int userInput;

        cin >> userInput;

        if(cin.fail()){

            clearBadInput();
            cout << "\nPlease enter a valid input!!" << endl;
            continue;
        }

        if(userInput == 1){

            cout << "Hello " << user1.getUserName() << "\n" << endl;
            cout << "Here's your current balance: " << endl;
            cout << "$" << user1.getBalance() << "\n" << endl;
        }
        else if(userInput == 2){

            deposit(user1);
        }
        else if(userInput == 3){

            withdraw(user1);
        }
        else if(userInput == 4){

            cout << "\nExiting the Program...." << endl;
            stillRunning = false;
        }
        else{

            cout << "\nPlease enter a valid input!!" << endl;
        }
    }

    return 0;
}