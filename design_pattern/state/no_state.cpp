#include <iostream>
using namespace std;

enum NetworkState
{
    init,
    open,
    connect,
    close
};

class NetwordProcessor
{
private:
    NetworkState m_state;
public:
    NetwordProcessor (NetworkState state = init):m_state(state) {}
    void oper1()
    {
        if (m_state == init)
        {
            cout << "state is init, you should open it." << endl;
            // other operator ...
            m_state = open;
        }
        else if (m_state == open)
        {
            cout << "state is open, you should connect it." << endl;
            // other operator ...
            m_state = connect;
        }
        else if (m_state == connect)
        {
            cout << "state is connect, you can transfer data." << endl;
            // other operator ...
            m_state = close;
        }
        else if (m_state == close)
        {
            cout << "state is close." << endl;
            // other operator ...
        }
        else
        {
            cout << "state is error." << endl;
            // other operator ...
        }
    }
    void oper2 ()
    {
        if (m_state == init)
        {
            cout << "state is init, you should open it." << endl;
            // some other operator ...
            m_state = open;
        }
        else if (m_state == open)
        {
            cout << "state is open, you should connect it." << endl;
            // other operator ...
            m_state = connect;
        }
        else if (m_state == connect)
        {
            cout << "state is connect, you can transfer data." << endl;
            // other operator ...
            m_state = close;
        }
        else if (m_state == close)
        {
            cout << "state is close." << endl;
            // other operator ...
        }
        else
        {
            cout << "state is error." << endl;
            // other operator ...
        }
    }
};

int main (void)
{
    NetwordProcessor np(close);
    np.oper1();
    return 0;
}

// 上面这种写法在扩展添加一种NetworkState时是比较麻烦的，需要修改的代码比较多。
