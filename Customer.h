#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Customer {
private:
    int id;
    string name;
    vector<Account> accounts;

public:
    Customer(int i, const string& n);
    void addAccount(const Account& acc, BankSystem& bank);
    double getTotalBalance() const;
    void printReport() const;
    int getId() const;
    string getName() const;
    const vector<Account>& getAccounts() const;
};

#endif