#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class BranchManagement
{

public:
    BranchManagement() {}

    static void viewAllBranches()
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
    static void viewBranchDetails(Branch branch)
    {
        cout << "Branch Details" << endl;
        cout << "\n";
        cout << "Branch Name: " << branch.BranchName << endl;
        cout << "Branch Code: " << branch.BranchCode << endl;
        cout << "Branch Address: " << branch.BranchAddress << endl;
        cout << "City: " << branch.City << endl;
        cout << "Province: " << branch.Province << endl;
    }
    static string comapareBranches()
    {
    }
    static vector<Branch> searchBranchByBranchProvince(string prov)
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
    static void createExistingBranches()
    {
        vector<Branch> branches = {

            Branch("Musgrave Centre STD", "10322", "115 Musgrave Road", "Durban", "KZN"),
            Branch("Waterfront STD", "80012", "19 Dock Road", "Cape Town", "WC"),
            Branch("Menlyn Park STD", "01815", "Atterbury Rd & Lois Ave", "Pretoria", "GAU"),
            Branch("Gateway Theatre STD", "43190", "1 Prestige Place", "Umhlanga", "KZN"),
            Branch("Rosebank Mall STD", "21960", "50 Bath Avenue", "Johannesburg", "GAU"),
            Branch("Walmer Park STD", "60701", "16th Avenue", "Gqeberha", "EC"),
            Branch("Loch Logan STD", "93014", "105 Henry Street", "Bloemfontein", "FS"),
            Branch("Liberty Mall STD", "32011", "50 Sanctuary Road", "Pietermaritzburg", "KZN"),
            Branch("Ballito Junction STD", "44203", "Leonora Drive", "Ballito", "KZN"),
            Branch("Somerset Mall STD", "71302", "Centenary Drive", "Somerset West", "WC")

        };

        ofstream file("branches.bat");

        for (Branch branch : branches)
        {
            try
            {
                if (!file.is_open())
                {
                    throw "File could not open.";
                };

                file << branch.BranchName << ","
                     << branch.BranchCode << ","
                     << branch.BranchAddress << ","
                     << branch.City << ","
                     << branch.Province << endl;

                file.close();
            }
            catch (...)
            {
                cout << "Error while writting to file";
                if (file.is_open())
                {
                    file.close();
                }
            }
        }
    }
};

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