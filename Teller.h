#pragma once
#include <string>

using namespace std;

class Teller
{

public:
    string TellerId;
    string FullName;
    string EncryptedPassword;
    string BranchCode;

public:
    // Constructor
    Teller(string id, string name, string pass, string code)
        : TellerId(id), FullName(name), EncryptedPassword(pass), BranchCode(code) {};

    //
    void RegisterCustomer(
        string AccountNumber,
        string Fullname,
        string SaId,
        string ContactNumber,
        string Email,
        string PhysicalAddress,
        string DateOfBirth,
        double InitialDeposit,
        string BranchCode,
        string PIN); // done

    void GenerateReport();                                   // done
    bool validateCustomerPin(string pin);                    // done
    void ViewCustomerDetails(Account acc);                   // done
    bool Login(string intputTellerId, string inputPassword); // success
    void StoreTellerCredentials(
        string TellerId,
        string FullName,
        string EncryptedPassword,
        string BranchCode);      // done
    string generateTellerId();   // done
    string GenerateFiveDigits(); // done
    void customer_account_summary(string pin);

    void customer_daily_transactions(string pin);

    string GenerateAccountNumber(string tellerId, string typeOfAccount); // done
};
