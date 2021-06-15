#include <iostream>
using namespace std;

// 计算各个国家税法 不用设计模式版本

enum tax_country
{
    china_tax,
    german_tax,
    usa_tax,
    france_tax // 增加法国
};

class caculate_tax
{
public:
    caculate_tax (tax_country country):m_country(country) {}
    double get_tax ()
    {
        switch (m_country)
        {
            case china_tax:
                cout << "get china tax" << endl;
                break;
            case german_tax:
                cout << "get german tax" << endl;
                break;
            case usa_tax:
                cout << "get usa tax" << endl;
                break;
            case france_tax:  //增加法国税法计算。每增加一个国家都要修改代码
                cout << "get france tax" << endl;
                break;
            default:
                cout << "unknown country" << endl;
                break;
        }
    }
private:
    tax_country m_country;
};


int main (void)
{
    caculate_tax tax (usa_tax);
    tax.get_tax ();
    return 0;
}
