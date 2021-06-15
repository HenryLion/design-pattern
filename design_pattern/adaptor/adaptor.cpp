#include <iostream>
using namespace std;

// 在软件系统中，由于应用环境的变化，常常需要将“一些现存的对象”放在新的环境中应用，但是新环境要求的接口是这些现存对象所不满足的
// 如何应对这种“迁移的变化”？如何既能利用现有对象的良好实现，同时又能满足新的应用环境所要求的接口？

// 适配器模式: 将一个类的接口转换成客户希望的另一个接口。Adapter模式使得原本由于接口不兼容而不能在一起工作的那些类可以一起工作。
class Person
{
public:
    void eat () { cout << "Person eat" << endl; }
    void drink () { cout << "Person drink" << endl; }
};


// 新接口
class ITarget
{
public:
    virtual void process () = 0;
};

// 老接口
class IOldInterface
{
public:
    virtual void eat () = 0;
    virtual void drink () = 0;
};

// 适配类
class Adapter : public ITarget
{
public:
    Adapter (IOldInterface *p) : m_pInter(p) {}
    virtual void process () 
    {
        m_pInter->eat();
        m_pInter->drink();
    }
private:
    IOldInterface *m_pInter;
};

// 老接口实体类
class ConcreteOld : public IOldInterface
{
public:
    virtual void eat () { cout << "Old eat" << endl; }
    virtual void drink () { cout << "Old drink" << endl;}
};

int main (void)
{
    IOldInterface *p_old = new ConcreteOld();
    ITarget *p_tar = new Adapter(p_old);
    p_tar->process ();
    return 0;
}
