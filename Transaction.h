#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
using namespace std;
enum class TransactionType { DEPOSIT, WITHDRAWAL, TRANSFER };

class Transaction {
private:
    int id;
    TransactionType type;
    double amount;
    string timestamp;
    int accountId;

public:
    Transaction(int i, TransactionType t, double amt, int accId, const string& ts);
    int getId() const;
    TransactionType getType() const;
    double getAmount() const;
    string getTimestamp() const;
    int getAccountId() const;

    bool operator==(const Transaction& other) const;
    Transaction operator+(const Transaction& other) const;
    void print() const;
};

#endif