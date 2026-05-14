#include "UserAccount.h"

UserAccount::UserAccount(double balanceToSet, std::string nameToSet){

    this->balance = balanceToSet;
    this->userName = nameToSet;
}

UserAccount::UserAccount(){

    this->balance = 1000.00;
    this->userName = "default userName";
}

double UserAccount::getBalance(){

    return this->balance;
}

std::string UserAccount::getUserName(){

    return this->userName;
}

void UserAccount::setBalanceTo(double balanceToSet){

    this->balance = balanceToSet;
}

void UserAccount::setNameTo(std::string nameToSet){

    this->userName = nameToSet;
}