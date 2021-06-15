#include <iostream>
#include <string>
using namespace std;

class Colleague;

class Mediator
{
public:
    virtual void Send (string msg, Colleague *clg) = 0;
};

class Colleague
{
public:
    Colleague (Mediator *mid):m_mid(mid) {}
protected:
    Mediator *m_mid;
};

class Colleague_1 : public Colleague
{
public:
    Colleague_1 (Mediator *mid) : Colleague(mid) {}
    virtual void Send(string msg)
    {
        m_mid->Send(msg, this);
    }
    void Notify (string msg)
    {
        cout << "Colleague_1 received: " << msg << endl;
    }
};


class Colleague_2 : public Colleague
{
public:
    Colleague_2 (Mediator *mid) : Colleague (mid) {}
    virtual void Send(string msg)
    {
        m_mid->Send(msg, this);
    }
    void Notify (string msg)
    {
        cout << "Colleague_2 received: " << msg << endl;
    }
};

class ConcreteMediator : public Mediator
{
public:
    void set (Colleague_1 *c) { c1 = c; }
    void set (Colleague_2 *c) { c2 = c; }
    void Send (string msg, Colleague *clg)
    {
        if (clg == c1) c2->Notify(msg);
        else c1->Notify(msg);
    }
private:
    Colleague_1 *c1;
    Colleague_2 *c2;
};

int main ()
{
    ConcreteMediator *m = new ConcreteMediator();
    Colleague_1 *c1 = new Colleague_1 (m);
    Colleague_2 *c2 = new Colleague_2 (m);

    m->set (c1);
    m->set (c2);

    c1->Send ("nihao");
    c2->Send ("en, nihao");

    delete m;
    delete c1;
    delete c2;
    return 0;
}
