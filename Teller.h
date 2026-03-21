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
        double InitialDeposit,
        string BranchCode,
        string PIN); // done

    void GenerateReport();
    bool validateCustomerPin(string pin);
    void ViewCustomerDetails(Account acc);                   // done
    bool Login(string intputTellerId, string inputPassword); // success
    void StoreTellerCredentials(
        string TellerId,
        string FullName,
        string EncryptedPassword,
        string BranchCode);      // done
    string generateTellerId();   // done
    string GenerateFiveDigits(); // done

    string GenerateAccountNumber(string tellerId, string typeOfAccount); // done
};
