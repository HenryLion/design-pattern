#include <iostream>
using namespace std;

/* 不实用装饰模式的结果就是导致随着功能的扩展，类的个数会出现暴增  */
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

// 我们在做加密文件流的时候，不能直接在file_stream类里面做加密，因为可能有需求要做不加密的读写
class crypt_file_stream : public file_stream // 加密文件流
{
public:
    virtual void read ()
    {
        cout << "do crypt read file_stream" << endl;
        file_stream::read();
    }
    virtual void wirte ()
    {
        cout << "do crypt write file_stream" << endl;
        file_stream::write();
    }

};

// 加密内存流

class crypt_memory_stream : public memory_stream // 加密文件流
{
public:
    virtual void read ()
    {
        cout << "do crypt read memory_stream" << endl;
        memory_stream::read();
    }
    virtual void wirte ()
    {
        cout << "do crypt write memory_stream" << endl;
        memory_stream::write();
    }

};

// 文件流缓冲
class buf_file_stream : public file_stream // 加密文件流
{
public:
    virtual void read ()
    {
        cout << "do buf read file_stream" << endl;
        file_stream::read();
    }
    virtual void wirte ()
    {
        cout << "do buf write file_stream" << endl;
        file_stream::write();
    }

};

// 缓冲内存流

class buf_memory_stream : public memory_stream // 加密文件流
{
public:
    virtual void read ()
    {
        cout << "do buf read memory_stream" << endl;
        memory_stream::read();
    }
    virtual void wirte ()
    {
        cout << "do buf write memory_stream" << endl;
        memory_stream::write();
    }

};

int main (void)
{
    stream * stream = new buf_memory_stream;
    stream->read ();
    return 0;
}
