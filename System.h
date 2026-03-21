#include <iostream>

using namespace std;

class System
{
private:
    static void set_sample_customers() {};
    static void set_sample_transactions() {};
    static void set_sample_tellers() {};
    static void set_sample_branches() {};
    static void back_up_to_csv() {};
    static void back_up_to_text_file() {};

public:
    System() {};

    static void configure_system();
};