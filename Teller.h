#pragma once
#include <string>

using namespace std;

class Teller
{

private:
    string TellerId;
    string FullName;
    string EncryptedPassword;
    string BranchCode;

public:
    // Constructor
    Teller(string TellerId, string FullName, string EncryptedPassword, string BranchCode);

    //
    void RegisterCustomer(
        string AccountNumber,
        string Fullname,
        string SaId,
        string ContactNumber,
        string Email,
        string PhysicalAddress,
        string DateOfBirth,
        string AccountType,
        string InitialDeposit,
        string BranchCode,
        string PIN);

    void ViewCustomerDetails();
    void GenerateReport();
    bool validateCustomerPin(string pin);

    void Deposit(double amount, string customerPin);
    void Withdraw(string customerPin);
    void Transfer(string customerPin);

    bool Login(); // success
    void StoreTellerCredentials(string TellerId, string FullName, string EncryptedPassword, string BranchCode);
    string generateTellerId();

    string GenerateAccountNumber(string account, string branch, string lastDigits);
};