#include <vector>
#include <iostream>

using namespace std;

class Branch
{
public:
    Branch(
        string BranchName,
        string BranchCode,
        string BranchAddress,
        string City,
        string Province)
    {
        this->BranchName = BranchName;
        this->BranchCode = BranchCode;
        this->BranchAddress = BranchAddress;
        this->City = City;
        this->Province = Province;
    }
    string BranchName;
    string BranchCode;
    string BranchAddress;
    string City;
    string Province;
};

class BranchManagement
{
public:
    BranchManagement() {};
    static string comapareBranches();
    static void viewBranchDetails(Branch branch);
    static void viewAllBranches();
    static vector<Branch> searchBranchByBranchProvince(string prov);
};
