#pragma once
#include <string>

using namespace std;

class Account
{
private:
    double balance;

public:
    string AccountNumber;
    string Fullname;
    string SaId;
    string ContactNumber;
    string Email;
    string PhysicalAddress;
    string DateOfBirth;
    double InitialDeposit;
    string BranchCode;
    string PIN;
    double interest;

public:
    Account(
        string accNo,
        string fname,
        string id,
        string contactNum,
        string email,
        string physicalAdd,
        string dob,
        double initDepo,
        string branchCode,
        string pin)
        : AccountNumber(accNo),
          Fullname(fname),
          SaId(id),
          ContactNumber(contactNum),
          Email(email),
          PhysicalAddress(physicalAdd),
          DateOfBirth(dob),
          InitialDeposit(initDepo),
          BranchCode(branchCode),
          PIN(pin)
    {
    }
    bool login(string accountNumber, string pin);                         // done
    void ChangePin(string newPin, string currentPin);                     // done
    void ViewAccountStatement(string pin);                                // done
    vector<string> GetTransactions(string pin);                           // done
    void Deposit(double amount, string customerPin);                      // done
    void Withdraw(double amount, string customerPin);                     // done
    void Transfer(string customerPin, double amount, string receiverPin); // done only balance issue left
    string GenerateFiveDigits();                                          // done
    bool validateId(string id);                                           // done
    bool validateEmail(string email);                                     // done
    bool validatePin(string pin);                                         // done
    virtual double getInterest() const
    {
        return 0.01;
    }; // done

    // Construct destructor
    virtual ~Account() {};
};

class Savings : public Account
{
public:
    Savings(
        string accNo,
        string fname,
        string id,
        string contactNum,
        string email,
        string physicalAdd,
        string dob,
        double initDepo,
        string branchCode,
        string pin) : Account(accNo, fname, id, contactNum, email, physicalAdd, dob, initDepo, branchCode, pin) {}
    double getInterest() const override
    {
        return 0.002;
    }
};

class Cheque : public Account
{
public:
    Cheque(
        string accNo,
        string fname,
        string id,
        string contactNum,
        string email,
        string physicalAdd,
        string dob,
        double initDepo,
        string branchCode,
        string pin)
        : Account(accNo, fname, id, contactNum, email, physicalAdd, dob, initDepo, branchCode, pin) {}
    double getInterest() const override
    {
        return 0.002;
    }
};
class FixedDeposit : public Account
{
public:
    FixedDeposit(
        string accNo,
        string fname,
        string id,
        string contactNum,
        string email,
        string physicalAdd,
        string dob,
        double initDepo,
        string branchCode,
        string pin) : Account(accNo, fname, id, contactNum, email, physicalAdd, dob, initDepo, branchCode, pin) {}
    double getInterest() const override
    {
        return 0.05;
    }
};
class Student : public Account
{
public:
    Student(
        string accNo,
        string fname,
        string id,
        string contactNum,
        string email,
        string physicalAdd,
        string dob,
        double initDepo,
        string branchCode,
        string pin) : Account(accNo, fname, id, contactNum, email, physicalAdd, dob, initDepo, branchCode, pin) {}
    double getInterest() const override
    {
        return 0.001;
    }
};
enum TransactionType
{
    Deposit,
    Withdraw,
    Transfer
};