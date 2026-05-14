#pragma once
#include <string>

class UserAccount{

    private:
    double balance;
    std::string userName;

    public:
    UserAccount(double balanceToSet, std::string nameToSet);
    UserAccount();

    double getBalance();
    std::string getUserName();

    void setBalanceTo(double balanceToSet);
    void setNameTo(std::string nameToSet);
};