#include <iostream>

using namespace std;
class country_tax
{
public:
    virtual void get_tax () = 0;
};

class china_tax : public country_tax
{
public:
    virtual void get_tax ()
    {
        cout << "get china tax" << endl;
    }
};

class germany_tax : public country_tax
{
public:
    virtual void get_tax ()
    {
        cout << "get germany tax" << endl;
    }
};

class countryFactory
{
public:
    virtual country_tax *getCountryInstance () = 0;
};

class chinaCountryFactory : public countryFactory
{
public:
    virtual country_tax *getCountryInstance ()
    {
        return new china_tax;
    }
};

class germanyCountryFactory : public countryFactory
{
public:
    virtual country_tax *getCountryInstance ()
    {
        return new germany_tax;
    }
};

int main (void)
{
    countryFactory * factory = new germanyCountryFactory;
    country_tax *p_c_tax = factory->getCountryInstance();
    p_c_tax->get_tax ();
    return 0;
}


