#include <iostream>
using namespace std;

class Transaction
{
public:
    Transaction(string Date, TransactionType Type, double Interest, string Pin)
    {
        this->Date = Date;
        this->Type = Type;
        this->Interest = Interest;
        this->Pin = Pin;
    }
    string Date;
    TransactionType Type;
    double Interest;
    string Pin;

    void
    SaveTransaction(string date,
                    TransactionType type,
                    double interest,
                    string Pin);
};

enum TransactionType
{
    Deposit,
    Withdraw,
    Transfer
};