#include <iostream>
#include "Customer.h"
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <regex>
using namespace std;

bool Account::validatePin(string pin)
{

    ifstream file("customers.dat");

    if (!file.is_open())
    {
        cout << "File is closed." << endl;
        return false;
    }
    string line;
    bool bfound = false;

    while (getline(file, line))
    {
        int pinFromFilePosition = line.find_last_of(',');
        string pinFromFile = line.substr(pinFromFilePosition);
        if (pinFromFile == pin)
        {
            bfound = true;
            break;
        }
    }

    if (bfound == false)
    {
        cout << "Account with pin " << pin << " does not exist." << endl;
    }

    return bfound;
}
void Account::Deposit(double amount, string customerPin)
{
    if (!validatePin(customerPin))
    {
        cout << "Invalid Pin" << endl;
        return;
    }
    balance += amount;
    cout << "Deposit of R" << amount << " was made into your account.";
}
void Account::Withdraw(double amount, string customerPin)
{
    if (!validatePin(customerPin))
    {
        cout << "Invalid Pin" << endl;
        return;
    }
    string validateAnswer;
    cout << "Are you sure? Enter y/n" << endl;
    cin >> validateAnswer;

    if (validateAnswer == "y" || validateAnswer == "Y")
    {
        balance -= amount;
        cout << "R" << amount << " was withdrawn from your account." << endl;
    }
    else if (validateAnswer == "n" || validateAnswer == "N")
    {
        cout << "Withdrawal action was cancelled" << endl;
        return;
    }
    else
    {
        cout << "Invalid option choose y or n";
        return;
    };
}

bool Account::validateId(string id)
{
    return id.length() == 13;
}
string Account::GenerateFiveDigits()
{
    srand(time(0));
    int randomFiveDigit = rand() % 90000 + 10000;
    return to_string(randomFiveDigit);
}
void Account::ChangePin(string newPin, string currentPin)
{
    if (!validatePin(currentPin))
    {
        cout << "Invalid Pin." << endl;
        return;
    }

    cout << "Are your sure that your current pin? y/n" << endl;
    if (newPin.length() != 5)
    {
        cout << "Pin must be 5 digits long";
        return;
    }

    getline(cin, newPin);

    ifstream infile("customers.bat");
    ofstream outfile("temp.bat");

    string line;
    bool found = false;
    while (getline(infile, line))
    {
        stringstream ss(line);
        string accNo, fname, id, contactNum, email, physicalAdd, dob, branchCode, pin, initDepo;

        getline(ss, accNo, ',');
        getline(ss, fname, ',');
        getline(ss, id, ',');
        getline(ss, contactNum, ',');
        getline(ss, email, ',');
        getline(ss, physicalAdd, ',');
        getline(ss, dob, ',');
        getline(ss, initDepo, ',');
        getline(ss, branchCode, ',');
        getline(ss, pin, ',');

        if (pin == currentPin)
        {

            outfile << accNo
                    << "," << fname
                    << "," << id
                    << "," << contactNum
                    << "," << email
                    << "," << physicalAdd
                    << "," << dob
                    << "," << initDepo
                    << "," << branchCode
                    << "," << newPin << endl;

            found = true;
        }
        else
        {
            outfile << line << "\n";
        }
    }
    infile.close();
    outfile.close();

    remove("customers.bat");
    rename("temp.bat", "customers.bat");

    if (found)
    {
        cout << "Pin changed successfully." << endl;
    }
    else
    {
        cout << "User not found." << endl;
    }
}
bool Account::validateEmail(string email)
{
    const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    return std::regex_match(email, pattern);
}
void Account::ViewAccountStatement(string pin)
{
}

bool Account::login(string accountNumber, string inputPin)
{

    cout << "Enter your account number : " << endl;
    getline(cin, accountNumber);

    cout << "Enter your pin : " << endl;
    getline(cin, inputPin);

    ifstream file("customers.dat");

    string line;

    if (!file.is_open())
    {
        cout << "File is not open." << endl;
        return false;
    }

    bool found = false;

    while (getline(file, line))
    {

        stringstream ss(line);

        string accNo, fname, id, contactNum, email, physicalAdd, dob, branchCode, pin, initDepo;

        getline(ss, accNo, ',');
        getline(ss, fname, ',');
        getline(ss, id, ',');
        getline(ss, contactNum, ',');
        getline(ss, email, ',');
        getline(ss, physicalAdd, ',');
        getline(ss, dob, ',');
        getline(ss, initDepo, ',');
        getline(ss, branchCode, ',');
        getline(ss, pin, ',');

        if (accountNumber == accNo && pin == inputPin)
        {
            found = true;
            break;
        }
    }
    return found;
}

void Account::Transfer(string customerPin) {
    //
};