#include "Transaction.h"
using namespace std;
Transaction::Transaction(int i, TransactionType t, double amt, int accId, const string& ts)
    : id(i), type(t), amount(amt), accountId(accId), timestamp(ts) {}

int Transaction::getId() const { return id; }
TransactionType Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getTimestamp() const { return timestamp; }
int Transaction::getAccountId() const { return accountId; }

bool Transaction::operator==(const Transaction& other) const {
    return (type == other.type && amount == other.amount && accountId == other.accountId);
}

Transaction Transaction::operator+(const Transaction& other) const {
    return Transaction(0, type, amount + other.amount, accountId, timestamp);
}

void Transaction::print() const {
    string typeStr;
    switch (type) {
        case TransactionType::DEPOSIT: typeStr = "DEPOSIT"; break;
        case TransactionType::WITHDRAWAL: typeStr = "WITHDRAWAL"; break;
        case TransactionType::TRANSFER: typeStr = "TRANSFER"; break;
    }
    cout << "Transaction ID: " << id << ", Type: " << typeStr
              << ", Amount: " << amount << ", Account ID: " << accountId
              << ", Time: " << timestamp <<endl;
}