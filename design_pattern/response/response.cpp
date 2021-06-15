// 职责链模式

/* 动机：在软件构建过程中，一个请求可能被多个对象处理，到那时每个请求在运行时只能有一个接收者，
 * 如果显示指定，将必不可少的带来请求发送者与接受者的紧耦合
 * 如何使请求的发送者不需要指定具体的接收者？让请求的接收者自己在运行时决定来处理请求，
 * 从而使两者解藕*/

/* 使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系，将这些对象连成一条链
 * 并沿着这条链传递请求，直到有一个对象处理它为止--- GoF */

#include <iostream>
#include <string>

using namespace std;

enum Question_type
{
    SMALL,  // 小问题
    BIG,    // 大问题
    SERIOUS, // 严重问题
    UNKNOWN  // 未知问题
};

class Request
{
public:
    Request (Question_type type, string r):r_type (type), req (r) {}
//private:
    Question_type r_type;
    string req;
};

class ChainHandle // 处理链父类
{
public:
    ChainHandle (){}
    ~ChainHandle (){}
    void SetNextHandle (ChainHandle *handle) { m_NextHandle = handle; }
    virtual bool canHandle (const Request &req) = 0;
    virtual void HandleReq (Request req) = 0;
    void sendReq2NextHandle (Request req) 
    {
        if (m_NextHandle)
            m_NextHandle->handle(req);
        else
            cout << "Sorry, No one can handle this problem" << endl; // 这里可以弄一个default的兜底类来处理
    }
    void handle (Request req)
    {
        if (this->canHandle (req))
            this->HandleReq (req);
        else
            sendReq2NextHandle (req);
    }
private:
    ChainHandle *m_NextHandle;
};

class monitorHandle : public ChainHandle // 班长处理类
{
public:
    virtual bool canHandle (const Request &req) { return req.r_type == SMALL; }
    virtual void HandleReq (Request req) 
    {
        cout << "monitor handle " << req.req << " very good!!!" << endl;
    }
};

class headTeacherHandle: public ChainHandle // 班主任处理类
{
public:
    bool canHandle (const Request &req) { return req.r_type == BIG; }
    void HandleReq (Request req) 
    {
        cout << "head teacher handle " << req.req << " very good!!!" << endl;
    }
};

class principalHandle : public ChainHandle // 校长处理类
{
public:
    bool canHandle (const Request &req) { return req.r_type == SERIOUS; }
    void HandleReq (Request req) 
    {
        cout << "principal handle " << req.req << " very good!!!" << endl;
    }
};

int main (void)
{
    ChainHandle *m_hnd = new monitorHandle ();
    ChainHandle *h_hnd = new headTeacherHandle ();
    ChainHandle *p_hnd = new principalHandle ();
    m_hnd->SetNextHandle (h_hnd);
    h_hnd->SetNextHandle (p_hnd);
    Request req (UNKNOWN, "what is 1 add 1? ");
    h_hnd->handle (req);
    return 0;
}
