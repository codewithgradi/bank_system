#include "Teller.h"
#include "Cipher.h"

#include <iostream>
#include <fstream>
#include <vector>
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
    string PIN)
{

    // register logic
}

bool Teller::Login()
{
    string intputTellerId;
    string inputPassword;

    cout << "Enter your teller id : " << endl;
    cin >> intputTellerId;

    cout << "Enter your password : " << endl;
    cin >> inputPassword;

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
