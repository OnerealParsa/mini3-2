#include "BankSystem.h"
#include <ctime>
using namespace std;
int BankSystem::totalAccounts = 0;
int BankSystem::nextTransactionId = 1;

BankSystem::BankSystem() {}

void BankSystem::addCustomer(Customer& cust) {
    customers.push_back(cust);
}

void BankSystem::recordTransaction(const Account& acc, TransactionType type, double amount) {
    Transaction t(nextTransactionId++, type, amount, acc.getId(), getCurrentTime());
    transactions.push_back(t);
}

void BankSystem::recordTransfer(const Account& from, const Account& to, double amount) {
    Transaction t(nextTransactionId++, TransactionType::TRANSFER, amount, from.getId(), getCurrentTime());
    transactions.push_back(t);
}

void BankSystem::printAllCustomers() const {
    cout << "Total Accounts: " << totalAccounts <<endl;
    for (const auto& cust : customers) {
        cust.printReport();
        cout << "-------------------" <<endl;
    }
}

void BankSystem::printAllTransactions() const {
    cout << "=== All Transactions ===" << endl;
    for (const auto& trans : transactions) {
        trans.print();
    }
}

int BankSystem::getTotalAccounts() {
    return totalAccounts;
}

void BankSystem::incrementTotalAccounts() {
    totalAccounts++;
}

Customer* BankSystem::findCustomerById(int id) {
    for (auto& cust : customers) {
        if (cust.getId() == id) {
            return &cust;
        }
    }
    return nullptr;
}

string BankSystem::getCurrentTime() {
    time_t now = time(0);
    char buf[80];
    struct tm* timeinfo = localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buf);
}