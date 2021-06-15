#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;
class ProgressBar
{
public:
    virtual void ProduceBar () = 0;
    ~ProgressBar() {}
};

class PrintProgressBar : public ProgressBar
{
public:
    PrintProgressBar (char barChar = '.') : m_barChar (barChar) {}
    void ProduceBar () 
    {
        cout << m_barChar;
        cout.flush();
        cout << endl;
    }
     
private:
    char m_barChar;
};

class PrintProgressBarColor : public ProgressBar
{
public:
    void ProduceBar ()
    {
        cout << "PrintProgressBarColor ProduceBar";
        cout.flush();
        cout << endl;
    }
};


class mainProgress
{
public:
    mainProgress ( ) {}
    void notifyObserver ()
    {
        // do work...
        for (auto it = m_bars.begin(); it != m_bars.end(); ++it)
            (*it)->ProduceBar();
    }
    ~mainProgress()
    {
        for (auto it = m_bars.begin(); it != m_bars.end(); ++it)
        {
            if (*it != NULL)
                delete *it;
        }
    }
    void attach (ProgressBar *bar) { m_bars.push_back(bar); }
    
private:
    vector<ProgressBar *> m_bars;
};


int main (void)
{
    ProgressBar *p_bar = new PrintProgressBar('+');
    ProgressBar *p_bar_color = new PrintProgressBarColor ();

    mainProgress dowork;
    dowork.attach (p_bar);
    dowork.attach (p_bar_color);
    dowork.notifyObserver ();
    return 0;
}
