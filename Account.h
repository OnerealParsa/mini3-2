#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;
enum class AccountType { SAVINGS, CHECKING, CREDIT };

class BankSystem;

class Account {
private:
    int id;
    std::string ownerName;
    double balance;
    AccountType type;
    static const double MIN_BALANCE;

public:
    Account(int i, const std::string& name, double bal, AccountType t);
    int getId() const;
    std::string getOwnerName() const;
    double getBalance() const;
    AccountType getType() const;

    void deposit(double amount, BankSystem& bank);
    bool withdraw(double amount, BankSystem& bank);
    bool transfer(Account& to, double amount, BankSystem& bank);
    void printBalance() const;

    friend class BankSystem;
};

#endif