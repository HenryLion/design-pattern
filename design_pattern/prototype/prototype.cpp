#include <iostream>
#include <string>

using namespace std;

// 练习一下原型模式

class transportation
{
public:
    transportation (string name=""):m_name(name) {}
    virtual void set_name (string) = 0;
    virtual const string& get_name () = 0;
    virtual transportation *clone () = 0;
    virtual ~transportation () {}
protected:
    string m_name;
};

class car : public transportation
{
public:
    car (string name="") : transportation (name) {}
    car (const car& rhs) { this->m_name = rhs.m_name; }
    virtual void set_name (string name )
    {
        m_name = name;
    }
    virtual const string& get_name () { return m_name; }
    virtual transportation *clone() { return new car (*this); }
};

class plane : public transportation
{
public:
    plane (string name=""):transportation (name) {}
    virtual void set_name (string name ) { m_name = name;}
    virtual const string & get_name () { return m_name;}
    plane (const plane& rhs) { this->m_name = rhs.m_name; }
    virtual transportation *clone() { return new plane (*this); }
};


int main (void)
{
    transportation *my_car = new car();
    my_car->set_name ("Benz");
    cout << my_car->get_name () << endl;
    cout << "------------" << endl;

    transportation *clone_car = my_car->clone (); // 根据已有的对象创建一个新的对象。
    cout << clone_car->get_name() << endl;

    transportation *my_plane = new plane();
    my_plane->set_name ("Boeing");
    cout << my_plane->get_name() << endl;

    delete my_car;
    delete clone_car;
    delete my_plane;
    return 0;
}

