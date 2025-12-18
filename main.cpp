#include <iostream>
#include "BankSystem.h"

int main() {
    BankSystem bank;

    Customer c1(1, "Parsa");
    Account acc1(1, "Parsa", 1000.0, AccountType::SAVINGS);
    c1.addAccount(acc1, bank);
    bank.addCustomer(c1);

    Customer c2(2, "Mina");
    Account acc2(2, "Mina", 500.0, AccountType::CHECKING);
    c2.addAccount(acc2, bank);
    bank.addCustomer(c2);

    Customer* cust1 = bank.findCustomerById(1);
    if (cust1 && !cust1->getAccounts().empty()) {
        Account& aliAcc = const_cast<Account&>(cust1->getAccounts()[0]);
        aliAcc.deposit(200, bank);
        aliAcc.withdraw(50, bank);
    }

    Customer* cust2 = bank.findCustomerById(2);
    if (cust1 && cust2 && !cust1->getAccounts().empty() && !cust2->getAccounts().empty()) {
        Account& fromAcc = const_cast<Account&>(cust1->getAccounts()[0]);
        Account& toAcc = const_cast<Account&>(cust2->getAccounts()[0]);
        fromAcc.transfer(toAcc, 300, bank);
    }

    bank.printAllCustomers();
    bank.printAllTransactions();

    return 0;
}