#include <iostream>
#include "Teller.h"

using namespace std;

void TellerTasks()
{
    cout << "Enter  1 to login or 2 to create teller account" << endl;
    char entry;
    cin >> entry;
    if (entry == '1')
    {
        string tellerId, password;
        cout << "Enter teller ID: " << endl;
        cin >> tellerId;
        cout << "Enter teller ID: " << endl;
        cin >> password;
        Teller::Login(tellerId, password);
    }
    else if (entry == '2')
    {
        string fullName, password, branchCode;
        cout << "Enter teller full name: ";
        cin >> fullName;
        cout << "Enter teller password";
        cin >> password;
        cout << "Enter teller branch code: ";
        cin >> branchCode;
        string tellerId = Teller::generateTellerId();
        Teller teller = Teller(tellerId, fullName, password, branchCode);
        teller.StoreTellerCredentials(teller.TellerId, teller.FullName, teller.EncryptedPassword, teller.BranchCode);
    }
    else
    {
        return;
    }
}
void CustomerTasks()
{
}
int main()
{
    cout << "Welcome to The banking platform." << endl;
    cout << "Enter t : If you are a teller\nEnter c : if you are a customer" << endl;
    char inputForTask;
    cin >> inputForTask;
    if (inputForTask == 't')
    {
        TellerTasks();
    }
    else if (inputForTask == 'c')
    {
        CustomerTasks();
    }
    else
    {
        cout << "Invalid input enter t or c in lowercase." << endl;
    }

    return 0;
}