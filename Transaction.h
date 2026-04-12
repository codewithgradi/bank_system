#include <iostream>
using namespace std;

enum TransactionType
{
    Deposit,
    Withdraw,
    Transfer
};

class Transaction
{
public:
    Transaction(string Date, TransactionType Type, double Amount, string Pin)
    {
        this->Date = Date;
        this->Type = Type;
        this->Amount = Amount;
        this->Pin = Pin;
    }

    string Date;
    TransactionType Type;
    double Amount;
    string Pin;

    void SaveTransaction(vector<Transaction> &txs);
};