#include <iostream>
#include <vector>
#include "Customer.h"
#include "BranchManagement.h"
#include "Teller.h"
#include "Transaction.h"

using namespace std;

class System
{
public:
    static vector<Account> get_sample_customers();
    static vector<Branch> get_sample_branches();
    static vector<Teller> get_sample_tellers();
    static vector<Transaction> get_sample_transactions();
    static void load_all_data_from_binary();
    static void back_up_to_csv();
    static void save_to_dat_files();
    static void save_to_txt();

public:
    System() {};

    static void configure_system();
    static void quickRead(ifstream &f, string &s);
    static void quickWrite(ofstream &f, const string &s);
};