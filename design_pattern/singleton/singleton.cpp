#include <iostream>
#include <pthread.h>
using namespace std;

int g_val = 0;
class LockGuard
{
public:
    LockGuard () {}
    ~LockGuard () { 
        pthread_mutex_unlock (&m_mutex); 
        pthread_mutex_destroy (&m_mutex);
    }
    void Lock () { pthread_mutex_lock (&m_mutex); }
private:
    static pthread_mutex_t m_mutex;
};

pthread_mutex_t LockGuard::m_mutex = PTHREAD_MUTEX_INITIALIZER;

class Singleton
{
private:
    Singleton () {}
    Singleton (const Singleton& rhs) {}
public:
    void checkHasFood () { cout << "Has food to Momo." << endl; }
    static Singleton * g_instance;
    static Singleton * getInstance ();
};

Singleton * Singleton::g_instance = NULL;

// double check
Singleton* Singleton::getInstance ()
{
    if (NULL == g_instance)
    {
        LockGuard lock;
        lock.Lock ();
        if (NULL == g_instance)
        {
            g_instance = new Singleton();
        }
    }
    return g_instance;
}



int main (void)
{
    Singleton *ins = Singleton::getInstance();
    ins->checkHasFood ();
    cout << ins << endl;

    Singleton *that = Singleton::getInstance ();
    cout << that << endl;
    return 0;
}

