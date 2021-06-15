// 动机
// 在软件构件过程中，某些对象的状态在转换过程中，可能由于某种需要，要求程序能够回溯到对象之前处于某个点时的状态。如果使用一些公有接口来让其他对象的到对象的状态，便会暴露对象的实现细节
//
// 如何实现对象状态的良好保存与恢复？但同时又不会因此而破坏对象本身的封装性。
//
// 定义：
// 在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可以将该对象恢复到原先保存的状态。  ----- GOF


#include <iostream>
#include <string>
using namespace std;
// 简单实现

class memento
{
public:
    memento (string s):state(s) {}
    string get_state () { return state; }
    void set_state (string s) { state = s; }
private:
    string state;
};

class need_bakup
{
private:
    string state;
public:
    need_bakup (string s = "first"):state(s) {}
    memento create_memnto ()
    {
        memento m(this->state);
        return m;
    }
    void set_memento (memento m)
    {
        this->state = m.get_state();
    }
    void set_state (string s)
    {
        state = s;
    }
    void print_state () { cout << state << endl; }
};

int main (void)
{
    need_bakup n;
    n.print_state();
    n.set_state ("second");
    n.print_state ();
    memento bak = n.create_memnto(); // 建立n的快照
    n.set_state ("third");
    n.print_state ();
    n.set_memento (bak); // 用快照恢复n的状态
    n.print_state ();
    return 0;
}

