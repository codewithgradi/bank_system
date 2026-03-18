#include "Teller.h"
#include "Cipher.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
// #include <vector>
#include <sstream>
#include <string>

Teller::Teller(string TellerId, string FullName, string password, string BranchCode)
{
    this->TellerId = TellerId;
    this->FullName = FullName;
    EncryptedPassword = Cipher::Encrypt(password);
    this->BranchCode = BranchCode;
}

void Teller::RegisterCustomer(
    string accountNumber,
    string fullname,
    string saId,
    string contactNumber,
    string email,
    string physicalAddress,
    string dateOfBirth,
    double initialDeposit,
    string branchCode,
    string pIN)
{
    if (Login(TellerId, EncryptedPassword) == false)
    {
        cout << "Invalid session, login first" << endl;
        return;
    }

    cout << "What type of account are you opening ? " << endl;
    cout << "0 = Savings " << endl;
    cout << "1 = Cheque" << endl;
    cout << "2 = FixedDeposit" << endl;
    cout << "3 = Student" << endl;

    int accType;
    cin >> accType;

    Account *acc;

    if (accType == 0)
    {
        acc = new Savings(
            accountNumber,
            fullname,
            saId,
            contactNumber,
            email,
            physicalAddress,
            dateOfBirth,
            initialDeposit,
            branchCode,
            pIN);
    }
    else if (accType == 1)
    {
        acc = new Cheque(
            accountNumber,
            fullname,
            saId,
            contactNumber,
            email,
            physicalAddress,
            dateOfBirth,
            initialDeposit,
            branchCode,
            pIN);
    }
    else if (accType == 2)
    {
        acc = new FixedDeposit(
            accountNumber,
            fullname,
            saId,
            contactNumber,
            email,
            physicalAddress,
            dateOfBirth,
            initialDeposit,
            branchCode,
            pIN);
    }
    else if (accType == 3)
    {
        acc = new Student(
            accountNumber,
            fullname,
            saId,
            contactNumber,
            email,
            physicalAddress,
            dateOfBirth,
            initialDeposit,
            branchCode,
            pIN);
    }
    else
    {
        cout << "Invalid option. Enter 0,1,2 or 3 : " << endl;
        return;
    }

    cout << "Account was created. " << endl;
}

bool Teller::Login(

    string intputTellerId,
    string inputPassword)
{

    ifstream file("tellers.bat");
    string line;

    if (!file.is_open())
    {
        cout << "Error: Could not open file" << endl;
    }

    while (getline(file, line))
    {
        stringstream ss(line);
        string tellerId, fullname, password, branchCode;

        getline(ss, tellerId, ',');
        getline(ss, fullname, ',');
        getline(ss, password, ',');
        getline(ss, branchCode, ',');

        if (tellerId == intputTellerId && password == inputPassword)
        {
            cout << "Welcome, " << fullname << endl;
            file.close();
            break;
            return true;
        }
    }

    file.close();
    return false;
}

void StoreTellerCredentials(
    string TellerId,
    string FullName,
    string EncryptedPassword,
    string BranchCode)
{
    ofstream file("tellers.bat", ios::app);

    if (!file.is_open())
    {
        cout << "Could not save credentials of teller." << endl;
    };

    file << TellerId << "," << FullName << "," << EncryptedPassword << "," << BranchCode << endl;
    cout << "Data saved successfully" << endl;
    file.close();
};

void Teller::ViewCustomerDetails(Account customerAccount)
{
    cout << "Account profile" << endl;
    cout << "Account Number : " << customerAccount.AccountNumber << endl;
    cout << "Full Name : " << customerAccount.Fullname << endl;
    cout << "ID Number : " << customerAccount.SaId << endl;
    cout << "Contact Number : " << customerAccount.ContactNumber << endl;
    cout << "Email  : " << customerAccount.Email << endl;
    cout << "Account Number : " << customerAccount.PhysicalAddress << endl;
    cout << "Date of Birth  : " << customerAccount.DateOfBirth << endl;
    cout << "Initial Deposit : " << customerAccount.InitialDeposit << endl;
    cout << "Branch Code : " << customerAccount.BranchCode << endl;
    cout << "PIN  : " << customerAccount.PIN << endl;
}

// string Teller::GenerateAccountNumber(){}