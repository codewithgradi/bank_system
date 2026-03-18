#pragma once
#include <string>

using namespace std;

class Account
{

private:
    string AccountNumber;
    string Fullname;
    string SaId;
    string ContactNumber;
    string Email;
    string PhysicalAddress;
    string DateOfBirth;
    string AccountType;
    string InitialDeposit;
    string BranchCode;
    string PIN;

    double balance;

public:
    bool login(string accountNumber, string pin);
    void ChangePin(string newPin);
    void ViewAccountStatement();
    void Deposit(double amount, string customerPin);
    void Withdraw(string customerPin);
    void Transfer(string customerPin);
    string GenerateFiveDigits();
    bool validateId(string id);
    bool validateEmail(string email);
};

class Savings : Account
{
};
class Cheque : Account
{
};
class FixedDeposit : Account
{
};
class Student : Account
{
};
