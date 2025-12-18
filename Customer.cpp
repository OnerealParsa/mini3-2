#include "Customer.h"
#include "BankSystem.h"
using namespace std;
Customer::Customer(int i, const string& n) : id(i), name(n) {}

void Customer::addAccount(const Account& acc, BankSystem& bank) {
    accounts.push_back(acc);
    bank.incrementTotalAccounts();
}

double Customer::getTotalBalance() const {
    double total = 0.0;
    for (const auto& acc : accounts) {
        total += acc.getBalance();
    }
    return total;
}

void Customer::printReport() const {
    cout << "Customer ID: " << id << ", Name: " << name <<endl;
    for (const auto& acc : accounts) {
        acc.printBalance();
    }
    cout << "Total Balance: " << getTotalBalance() <<endl;
}

int Customer::getId() const { return id; }
string Customer::getName() const { return name; }
const vector<Account>& Customer::getAccounts() const { return accounts; }