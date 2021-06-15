#include <iostream>

using namespace std;

class animal
{
public: 
    virtual void eat () = 0;
};

class dog : public animal
{
public:
    virtual void eat ()
    {
        cout << "dog eat" << endl;
    }
};

class cat : public animal
{
public:
    virtual void eat ()
    {
        cout << "cat eat" << endl;
    }
};



class animalFactory
{
public:
    virtual animal *get_animal () = 0;
};

class dogFactory : public animalFactory
{
public:
    virtual animal *get_animal ()
    {
        return new dog();
    }
};

class catFactory : public animalFactory
{
public:
    virtual animal *get_animal ()
    {
        return new cat ();
    }
};

class animal_mng
{
private:
    animal *m_animal;
public:
    animal_mng (animalFactory *a_factory):m_animal(a_factory->get_animal()) {}
    ~animal_mng ()
    {
        if (m_animal)
            delete m_animal;
    }

    void animal_eat () 
    {
        m_animal->eat();
    }
};


int main (void)
{
    animalFactory *p_factory = new dogFactory;
    animal * p_animal = p_factory->get_animal ();
    p_animal->eat ();
    cout << "-----------" << endl;

    animal_mng *p_mng = new animal_mng(new (catFactory));
    p_mng->animal_eat ();
    return 0;
}
