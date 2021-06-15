#include <iostream>

using namespace std;

// 外观模式

class ConnectDb
{
public:
    ConnectDb ()  {}
    virtual void InitDb () = 0;
    virtual void ReadDb () = 0;
    virtual void WriteDB () = 0;
};

class MySql : public ConnectDb
{
public:
    void InitDb () { cout << "MySql InitDb" << endl; }
    void ReadDb () { cout << "MySql ReadDB" << endl; }
    void WriteDB () { cout << "MySql WriteDB" << endl; }
};

class Orecal : public ConnectDb
{
public:
    void InitDb () { cout << "Orecal InitDb" << endl; }
    void ReadDb () { cout << "Orecal ReadDb" << endl; }
    void WriteDB () { cout << "Orecal WriteDB" << endl; }
};

void OperatorDb ()
{
    ConnectDb *p_db = new MySql();
    p_db->InitDb();
    p_db->ReadDb();
    p_db->WriteDB();
    delete p_db;
}

int main (void)
{
    OperatorDb ();
    return 0;
}
