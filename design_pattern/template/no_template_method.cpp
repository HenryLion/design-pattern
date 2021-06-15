#include <iostream>
using namespace std;

class base_flow
{
public:
    void init_env (int num)
    {
        cout << "there are " << num <<  " product." << endl;
    }

    void stat (int num)
    {
        cout << "sales " << num <<  " items." << endl;
    }
};

class sales_system
{
public:
    void sale (float price)
    {
        cout << "sale " << price << " RMB" << endl;
    }

    void get_product (int num)
    {
        cout << "get " << num << " items" << endl;
    }
};


int main (void)
{
    base_flow b_flow;
    b_flow.init_env (10);
    sales_system s_system;
    s_system.sale (3.14);
    s_system.get_product (3);
    b_flow.stat (4);

    return 0;
}
