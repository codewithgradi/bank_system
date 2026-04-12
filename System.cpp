#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "System.h"
#include "BranchManagement.h"
#include "Teller.h"
#include "Transaction.h"
#include "Customer.h"
#include "Cipher.h"

using namespace std;

// SAMPLE DATA

vector<Account> System::get_sample_customers()
{
    return {
        {"1001", "Sipho Sithole", "9201015001081", "0711234567", "sipho@mail.com", "12 Fox St", "1992-01-01", 1500.0, "ZA-001", "1234"},
        {"1002", "Anika Naidoo", "8505205002082", "0822345678", "anika@mail.com", "44 Marine Dr", "1985-05-20", 5000.0, "ZA-003", "5678"},
        {"1003", "Pieter Marais", "7811125003083", "0633456789", "pieter@mail.com", "99 Oak Ave", "1978-11-12", 250.0, "ZA-006", "9012"},
        {"1004", "Zanele Khoza", "9508305004084", "0744567890", "zanele@mail.com", "21 Gwigwi St", "1995-08-30", 12000.0, "ZA-001", "3456"},
        {"1005", "David Smith", "8803155005085", "0815678901", "david@mail.com", "76 High Rd", "1988-03-15", 3000.0, "ZA-002", "7890"},
        {"1006", "Fatima Isaacs", "9112055006086", "0726789012", "fatima@mail.com", "15 Loop St", "1991-12-05", 450.0, "ZA-002", "1122"},
        {"1007", "Lebo Mokoena", "8206105007087", "0637890123", "lebo@mail.com", "3 Churchill Ln", "1982-06-10", 8000.0, "ZA-004", "3344"},
        {"1008", "Gary Wilson", "7504045008088", "0848901234", "gary@mail.com", "12 West St", "1975-04-04", 150.0, "ZA-010", "5566"},
        {"1009", "Naledi Cele", "9810105009089", "0759012345", "naledi@mail.com", "88 Ridge Rd", "1998-10-10", 2200.0, "ZA-007", "7788"},
        {"1010", "Johan Steyn", "8009255010080", "0610123456", "johan@mail.com", "5 Park Ln", "1980-09-25", 10500.0, "ZA-004", "9900"}};
}

vector<Branch> System::get_sample_branches()
{
    return {
        {"Sandton Central", "ZA-001", "5th St", "Johannesburg", "Gauteng"},
        {"V&A Waterfront", "ZA-002", "Breakwater Blvd", "Cape Town", "Western Cape"},
        {"Umhlanga Gateway", "ZA-003", "1 Palm Blvd", "Durban", "KwaZulu-Natal"},
        {"Brooklyn Mall", "ZA-004", "Veale St", "Pretoria", "Gauteng"},
        {"Somerset Mall", "ZA-005", "Centenary Dr", "Somerset West", "Western Cape"},
        {"Loch Logan", "ZA-006", "Henry St", "Bloemfontein", "Free State"},
        {"Riverside Mall", "ZA-007", "Madiba Dr", "Mbombela", "Mpumalanga"},
        {"Savannah Mall", "ZA-008", "Grimm St", "Polokwane", "Limpopo"},
        {"Mimosa Mall", "ZA-009", "Kellner St", "Bloemfontein", "Free State"},
        {"Vincent Park", "ZA-010", "Devereux Ave", "East London", "Eastern Cape"}};
}

vector<Teller> System::get_sample_tellers()
{
    return {
        {"T001", "Thabo Mokoena", "Pass123!", "ZA-001"},
        {"T002", "Sarah Jenkins", "Pass123!", "ZA-002"},
        {"T003", "Kavesh Naidoo", "Pass123!", "ZA-003"},
        {"T004", "Linda Williams", "Pass123!", "ZA-004"},
        {"T005", "Chris Botha", "Pass123!", "ZA-005"},
        {"T006", "Nomsa Khumalo", "Pass123!", "ZA-006"},
        {"T007", "Elena Rodriguez", "Pass123!", "ZA-007"},
        {"T008", "Musa Zondi", "Pass123!", "ZA-008"},
        {"T009", "Brad Smith", "Pass123!", "ZA-009"},
        {"T010", "Tessa Van Wyk", "Pass123!", "ZA-010"}};
}

vector<Transaction> System::get_sample_transactions()
{
    return {
        Transaction("2026-04-01", TransactionType::Deposit, 5000.0, "1234"),
        Transaction("2026-04-01", TransactionType::Deposit, 15000.0, "5678"),
        Transaction("2026-04-02", TransactionType::Withdraw, 200.0, "1234"),
        Transaction("2026-04-02", TransactionType::Transfer, 1000.0, "9012"),
        Transaction("2026-04-03", TransactionType::Deposit, 500.0, "3456"),
        Transaction("2026-04-03", TransactionType::Withdraw, 100.0, "7890"),
        Transaction("2026-04-04", TransactionType::Deposit, 2500.0, "1122"),
        Transaction("2026-04-04", TransactionType::Transfer, 300.0, "3344"),
        Transaction("2026-04-05", TransactionType::Withdraw, 50.0, "5566"),
        Transaction("2026-04-05", TransactionType::Deposit, 900.0, "7788"),
        Transaction("2026-04-06", TransactionType::Deposit, 4500.0, "9900"),
        Transaction("2026-04-06", TransactionType::Withdraw, 1000.0, "1234"),
        Transaction("2026-04-07", TransactionType::Transfer, 250.0, "5678"),
        Transaction("2026-04-07", TransactionType::Deposit, 120.0, "9012"),
        Transaction("2026-04-08", TransactionType::Withdraw, 500.0, "3456"),
        Transaction("2026-04-08", TransactionType::Deposit, 2000.0, "7890"),
        Transaction("2026-04-09", TransactionType::Transfer, 100.0, "1122"),
        Transaction("2026-04-09", TransactionType::Withdraw, 20.0, "3344"),
        Transaction("2026-04-10", TransactionType::Deposit, 750.0, "5566"),
        Transaction("2026-04-10", TransactionType::Transfer, 110.0, "7788")};
}

void System::configure_system()
{
    // This function initializes the data and creates the physical backup files
    save_to_dat_files();
    load_all_data_from_binary();
    back_up_to_csv();
    cout << "System configuration complete. All backup files generated." << endl;
}

void System::quickWrite(ofstream &f, const string &s)
{
    size_t len = s.size();
    f.write((char *)&len, sizeof(len));
    f.write(s.data(), len);
}
void System::quickRead(ifstream &f, string &s)
{
    size_t len;
    if (f.read((char *)&len, sizeof(len)))
    {
        s.resize(len);
        f.read(&s[0], len);
    }
}

void System::load_all_data_from_binary()
{
    vector<Branch> allBranches = {};
    vector<Transaction> allTransactions = {};
    vector<Teller> allTellers = {};
    vector<Account> allAccounts = {};
    // --- 1. LOAD BRANCHES ---
    ifstream bFile("branches.dat", ios::binary);
    if (bFile)
    {
        while (bFile.peek() != EOF)
        {
            string name, code, addr, city, prov;
            quickRead(bFile, name);
            quickRead(bFile, code);
            quickRead(bFile, addr);
            quickRead(bFile, city);
            quickRead(bFile, prov);

            if (!bFile.fail())
            {
                allBranches.push_back(Branch(name, code, addr, city, prov));
            }
        }
        bFile.close();
    }

    // --- 2. LOAD CUSTOMERS ---
    ifstream cFile("customers.dat", ios::binary);
    if (cFile)
    {
        while (cFile.peek() != EOF)
        {
            string accNo, fname, id, contact, email, addr, dob, bCode, pin;
            double initDepo;

            quickRead(cFile, accNo);
            quickRead(cFile, fname);
            quickRead(cFile, id);
            quickRead(cFile, contact);
            quickRead(cFile, email);
            quickRead(cFile, addr);
            quickRead(cFile, dob);
            cFile.read((char *)&initDepo, sizeof(double));
            quickRead(cFile, bCode);
            quickRead(cFile, pin);

            if (!cFile.fail())
            {
                allAccounts.push_back(Account(accNo, fname, id, contact, email, addr, dob, initDepo, bCode, pin));
            }
        }
        cFile.close();
    }

    // --- 3. LOAD TELLERS ---
    ifstream tFile("tellers.dat", ios::binary);
    if (tFile)
    {
        while (tFile.peek() != EOF)
        {
            string id, name, pass, bCode;
            quickRead(tFile, id);
            quickRead(tFile, name);
            string password = Cipher::Decrypt(pass);
            quickRead(tFile, password);
            quickRead(tFile, bCode);

            if (!tFile.fail())
            {
                allTellers.push_back(Teller(id, name, pass, bCode));
            }
        }
        tFile.close();
    }

    // --- 4. LOAD TRANSACTIONS ---
    ifstream txFile("transactions.dat", ios::binary);
    if (txFile)
    {
        while (txFile.peek() != EOF)
        {
            string date, pin;
            TransactionType type;
            double interest;

            quickRead(txFile, date);
            txFile.read((char *)&type, sizeof(type));
            txFile.read((char *)&interest, sizeof(double));
            quickRead(txFile, pin);

            if (!txFile.fail())
            {
                allTransactions.push_back(Transaction(date, type, interest, pin));
            }
        }
        txFile.close();
    }
}
void System::save_to_dat_files()

{
    // 1. SAVE BRANCHES
    ofstream bFile("branches.dat", ios::binary);
    auto branches = get_sample_branches();
    for (auto &x : branches)
    {
        quickWrite(bFile, x.BranchName);
        quickWrite(bFile, x.BranchCode);
        quickWrite(bFile, x.BranchAddress);
        quickWrite(bFile, x.City);
        quickWrite(bFile, x.Province);
    }
    bFile.close();

    // 2. SAVE CUSTOMERS (Accounts)
    ofstream cFile("customers.dat", ios::binary);
    auto customers = get_sample_customers();
    for (auto &x : customers)
    {
        quickWrite(cFile, x.AccountNumber);
        quickWrite(cFile, x.Fullname);
        quickWrite(cFile, x.SaId);
        quickWrite(cFile, x.ContactNumber);
        quickWrite(cFile, x.Email);
        quickWrite(cFile, x.PhysicalAddress);
        quickWrite(cFile, x.DateOfBirth);
        cFile.write((char *)&x.InitialDeposit, sizeof(double));
        quickWrite(cFile, x.BranchCode);
        quickWrite(cFile, x.PIN);
    }
    cFile.close();

    // 3. SAVE TELLERS
    ofstream tFile("tellers.dat", ios::binary);
    auto tellers = get_sample_tellers();
    for (auto &x : tellers)
    {
        quickWrite(tFile, x.TellerId);
        quickWrite(tFile, x.FullName);
        quickWrite(tFile, Cipher::Encrypt(x.EncryptedPassword));
        quickWrite(tFile, x.BranchCode);
    }
    tFile.close();

    // 4. SAVE TRANSACTIONS
    ofstream txFile("transactions.dat", ios::binary);
    auto txs = get_sample_transactions();
    for (auto &x : txs)
    {
        quickWrite(txFile, x.Date);
        txFile.write((char *)&x.Type, sizeof(x.Type));
        txFile.write((char *)&x.Amount, sizeof(double));
        quickWrite(txFile, x.Pin);
    }
    txFile.close();

    cout << "Binary backup complete for all categories!" << endl;
}
void System::back_up_to_csv()
{
    // 1. BACKUP CUSTOMERS
    ofstream cFile("customers_backup.csv");
    if (cFile.is_open())
    {
        // Optional: Add Header Row
        cFile << "AccountNumber,FullName,ID,Contact,Email,Address,DOB,Balance,BranchCode\n";

        auto customers = get_sample_customers();
        for (const auto &x : customers)
        {
            cFile << x.AccountNumber << ","
                  << x.Fullname << ","
                  << x.SaId << ","
                  << x.ContactNumber << ","
                  << x.Email << ","
                  << x.PhysicalAddress << "," // Note: If address has commas, this can break CSV
                  << x.DateOfBirth << ","
                  << x.InitialDeposit << ","
                  << x.BranchCode << "\n";
        }
        cFile.close();
    }

    // 2. BACKUP TELLERS
    ofstream tFile("tellers_backup.csv");
    if (tFile.is_open())
    {
        tFile << "TellerID,FullName,BranchCode\n"; // Header
        auto tellers = get_sample_tellers();
        for (const auto &x : tellers)
        {
            tFile << x.TellerId << ","
                  << x.FullName << ","
                  << x.BranchCode << "\n";
        }
        tFile.close();
    }
    cout << "CSV Backups created successfully." << endl;
}
void System::save_to_txt()
{
    // 1. SAVE BRANCHES
    ofstream bFile("branches_report.txt");
    if (bFile.is_open())
    {
        bFile << "SOUTH AFRICAN BRANCH LIST\n";
        bFile << "=========================\n";
        auto branches = get_sample_branches();
        for (const auto &x : branches)
        {
            bFile << "Name:    " << x.BranchName << "\n"
                  << "Code:    " << x.BranchCode << "\n"
                  << "City:    " << x.City << "\n"
                  << "Address: " << x.BranchAddress << "\n"
                  << "-------------------------\n";
        }
        bFile.close();
    }

    // 2. SAVE TRANSACTIONS
    ofstream txFile("transactions_log.txt");
    if (txFile.is_open())
    {
        txFile << "DAILY TRANSACTION LOG\n";
        txFile << "DATE\t\tTYPE\t\tAMOUNT\t\tPIN\n";
        txFile << "--------------------------------------------------\n";
        auto txs = get_sample_transactions();
        for (const auto &x : txs)
        {
            // Convert Enum to string for the text file
            string typeStr = (x.Type == TransactionType::Deposit) ? "Deposit " : (x.Type == TransactionType::Withdraw) ? "Withdraw"
                                                                                                                       : "Transfer";

            txFile << x.Date << "\t"
                   << typeStr << "\t"
                   << "R " << x.Amount << "\t\t"
                   << x.Pin << "\n";
        }
        txFile.close();
    }
    cout << "Text reports generated successfully." << endl;
}