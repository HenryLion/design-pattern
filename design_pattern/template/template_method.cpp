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

    void Run (void)
    {
        init_env (10);
        sale(3.14);
        get_product (3);
        stat (4);
    }
protected:
    virtual void sale (float price) = 0;
    virtual void get_product (int num) = 0;
};

class sales_system : public base_flow
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
    base_flow *p_flow = new sales_system;
    p_flow->Run();

    return 0;
}
