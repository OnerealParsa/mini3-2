#include "Account.h"
#include "BankSystem.h"
using namespace std;
const double Account::MIN_BALANCE = 100.0;

Account::Account(int i, const std::string& name, double bal, AccountType t)
    : id(i), ownerName(name), balance(bal), type(t) {}

int Account::getId() const { return id; }
std::string Account::getOwnerName() const { return ownerName; }
double Account::getBalance() const { return balance; }
AccountType Account::getType() const { return type; }

void Account::deposit(double amount, BankSystem& bank) {
    if (amount > 0) {
        balance += amount;
        bank.recordTransaction(*this, TransactionType::DEPOSIT, amount);
    }
}

bool Account::withdraw(double amount, BankSystem& bank) {
    if (amount > 0 && (balance - amount) >= MIN_BALANCE) {
        balance -= amount;
        bank.recordTransaction(*this, TransactionType::WITHDRAWAL, amount);
        return true;
    }
    return false;
}

bool Account::transfer(Account& to, double amount, BankSystem& bank) {
    if (withdraw(amount, bank)) {
        to.deposit(amount, bank);
        bank.recordTransfer(*this, to, amount);
        return true;
    }
    return false;
}

void Account::printBalance() const {
    cout << "Account ID: " << id << ", Owner: " << ownerName
              << ", Balance: " << balance << endl;
}