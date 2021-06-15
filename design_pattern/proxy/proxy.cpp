#include <iostream>
using std::cout;
using std::endl;

// 电信运营商
class ITelcomm
{
public:
    virtual void Recharge (int money) = 0;
};

// 中国移动
class CMCC : public ITelcomm
{
public:
    void Recharge (int money)
    {
        cout << "Recharge " << money << endl;
    }
};

// 创建代理点业务定制化：低于50不充值
class Proxy : public ITelcomm
{
public:
    Proxy():m_pCMCC (NULL) {}
    ~Proxy () { delete m_pCMCC; }

    void Recharge (int money)
    {
        if (money >= 50)
        {
            if (m_pCMCC == NULL)
                m_pCMCC = new CMCC();
            m_pCMCC->Recharge(money);
        }
        else
            cout << "Sorry, too little money." << endl;
    }
private:
    CMCC *m_pCMCC;
};

int main (void)
{
    Proxy *proxy = new Proxy ();
    proxy->Recharge(20);
    proxy->Recharge(100);
    delete proxy;
    return 0;
}
