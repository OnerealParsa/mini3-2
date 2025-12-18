#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H
using namespace std;
#include "Customer.h"
#include "Transaction.h"
#include <vector>

class BankSystem {
private:
    vector<Customer> customers;
    vector<Transaction> transactions;
    static int totalAccounts;
    static int nextTransactionId;

public:
    BankSystem();
    void addCustomer(Customer& cust);
    void recordTransaction(const Account& acc, TransactionType type, double amount);
    void recordTransfer(const Account& from, const Account& to, double amount);
    void printAllCustomers() const;
    void printAllTransactions() const;
    static int getTotalAccounts();
    void incrementTotalAccounts();
    Customer* findCustomerById(int id);
    static string getCurrentTime();
};

#endif