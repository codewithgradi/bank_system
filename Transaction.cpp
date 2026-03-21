#include <iostream>
#include "Transaction.h"
#include <fstream>

using namespace std;

void Transaction::SaveTransaction(
    string date,
    TransactionType type,
    double interest,
    string Pin)
{

    ofstream file("transations.dat");

    try
    {
        file << date << "," << type << "," << to_string(interest) << "," << Pin << endl;
    }
    catch (...)
    {
        cout << "There was a problem saving the transaction" << endl;
    }
}