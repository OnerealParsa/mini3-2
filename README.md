# Mini Project 3-2 — Bank System (C++)

A university assignment in C++ that implements a small banking system: customers, accounts and transactions are modeled as separate classes and coordinated by a central `BankSystem`.

## Classes

| Class | Responsibility |
|---|---|
| `Account` | A bank account (balance and account type) |
| `Customer` | A bank customer who owns accounts |
| `Transaction` | A single financial transaction record |
| `BankSystem` | Coordinates customers, accounts and transactions |

## Build & Run

```bash
g++ -std=c++17 -O2 -o bank main.cpp Account.cpp BankSystem.cpp Customer.cpp Transaction.cpp
./bank
```

## Concepts Demonstrated

Encapsulation, composition, and separation of model classes.
