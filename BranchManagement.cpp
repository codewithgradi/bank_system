#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "BranchManagement.h"

using namespace std;

Branch::Branch(string name, string code, string address, string city, string prov)
    : BranchName(name), BranchCode(code), BranchAddress(address), City(city), Province(prov) {}

void BranchManagement::viewAllBranches()
{
    ifstream file("branches.bat");
    string line;

    if (!file.is_open())
    {
        cout << "File is not open." << endl;
    };

    cout << "Available Branched" << endl;
    cout << "\n";

    while (getline(file, line))
    {

        stringstream ss(line);

        string bname, bcode, baddress, bcity, bprov;

        getline(ss, bname, ',');
        getline(ss, bcode, ',');
        getline(ss, baddress, ',');
        getline(ss, bcity, ',');
        getline(ss, bprov, ',');

        cout << "Branch Name: " << bname << "\t"
             << "Branch Code: " << bcode << "\t"
             << "Branch Address: " << baddress << "\t"
             << "City: " << bcity << "\t"
             << "Province : " << bprov << endl;
        ;
    }
}
void BranchManagement::viewBranchDetails(Branch branch)
{
    cout << "Branch Details" << endl;
    cout << "\n";
    cout << "Branch Name: " << branch.BranchName << endl;
    cout << "Branch Code: " << branch.BranchCode << endl;
    cout << "Branch Address: " << branch.BranchAddress << endl;
    cout << "City: " << branch.City << endl;
    cout << "Province: " << branch.Province << endl;
}
string BranchManagement::comapareBranches()
{
}
vector<Branch> BranchManagement::searchBranchByBranchProvince(string prov)
{

    ifstream file("branches.bat");

    string line;

    stringstream ss(line);
    vector<Branch> searches = {};

    while (getline(file, line))
    {
        string bname, bcode, baddress, bcity, bprov;

        getline(ss, bname, ',');
        getline(ss, bcode, ',');
        getline(ss, baddress, ',');
        getline(ss, bcity, ',');
        getline(ss, bprov, ',');

        if (prov == bprov)
        {
            searches.push_back(Branch(bname, bcode, baddress, bcity, bprov));
        }
    }

    return searches;
}
