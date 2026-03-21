#include <iostream>
#include <vector>
#include <fstream>
#include "BranchManagement.h"
#include "System.h"

// missing implementation

void System::set_sample_customers() {};
void System::set_sample_branches() {};
void System::set_sample_tellers() {};
void System::set_sample_transactions() {};
void System::back_up_to_csv() {};
void System::back_up_to_text_file() {};

void System::configure_system()
{
    set_sample_branches();
    set_sample_customers();
    set_sample_tellers();
    set_sample_transactions();
    back_up_to_csv();
    back_up_to_text_file();
}