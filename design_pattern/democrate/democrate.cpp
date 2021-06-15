#include <iostream>
using namespace std;

class stream   // 流接口
{
public:
    virtual void read () = 0; 
    virtual void write () = 0;
};

class file_stream : public stream  // 文件流
{
public:
    virtual void read () { cout << "file_stream::read" << endl; }
    virtual void write () { cout << "file_stream::write" << endl; }

};


class memory_stream : public stream  // 内存流
{
public:
    virtual void read () { cout << "memory_stream::read" << endl; }
    virtual void write () { cout << "memory_stream::write" << endl; }

};

class ext_stream : public stream  // 流功能扩展中间类
{
public:
    ext_stream (stream *sm):stm(sm) {}
    stream *stm;
};

class crypt_stream : public ext_stream
{
public:
    crypt_stream (stream *sm):ext_stream(sm)   {   }
    virtual void read ()
    {
        cout << "do crypt read" << endl;
        stm->read();
    }
    virtual void write ()
    {
        cout << "do crypt write" << endl;
        stm->write();
    }
};


class buf_stream : public ext_stream
{
public:
    buf_stream (stream *sm) : ext_stream(sm) {  }
    virtual void read ()
    {
        cout << "do buf read" << endl;
        stm->read();
    }
    virtual void write ()
    {
        cout << "do buf write" << endl;
        stm->write();
    }

};

int main (void)
{
    stream * s1 = new file_stream;
    crypt_stream *s2 = new crypt_stream (s1);
    s2->read ();
    cout << "---------" << endl;

    stream *s3 = new memory_stream;
    crypt_stream *s4 = new crypt_stream (s3);
    buf_stream *s5 = new buf_stream (s4);
    s5->write ();
    return 0;
}
