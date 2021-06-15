#include<iostream>
using namespace std;

// 网络状态接口类
class NetworkState
{
public:
    virtual void operator1 () = 0;
    virtual void operator2 () = 0;
    virtual ~NetworkState () {}
};

// 具体的网络状态类
class OpenState : public NetworkState
{
public:
    void operator1 ()
    {
        cout << "state is open, you can do operator1." << endl;
    }

    void operator2 ()
    {
        cout << "state is open, you can do operator2." << endl;
    }
};

class ConnectState : public NetworkState
{
public:
    void operator1 ()
    {
        cout << "state is connect, you can do operator1." << endl;
    }

    void operator2 ()
    {
        cout << "state is connect, you can do operator2." << endl;
    }
};

class CloseState : public NetworkState 
{
public:

    void operator1 ()
    {
        cout << "state is connect, you can do operator1." << endl;
    }

    void operator2 ()
    {
        cout << "state is connect, you can do operator2." << endl;
    }
};

// 网络处理函数，根据状态的不同处理函数也不同
class NetworkProcessor
{
    NetworkState *pState;
public:
    NetworkProcessor (NetworkState *state):pState(state) {}
    void operator1 ()
    {
        pState->operator1 ();
    }
    void operator2 ()
    {
        pState->operator2 ();
    }
    void setNetworkState (NetworkState *new_state) { pState = new_state; } //需要手动设置当前的网络状态
};

int main (void)
{
    NetworkState *s1 = new OpenState ();
    NetworkState *s2 = new ConnectState ();
    NetworkProcessor *p = new NetworkProcessor (s1);
    p->operator1 ();
    p->operator2();
    p->setNetworkState(s2);
    p->operator1 ();
    p->operator2();
    delete s1;
    delete s2;
    delete p;
    return 0;
}
