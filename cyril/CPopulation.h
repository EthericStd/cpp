#ifndef __CPopulation__
#define __CPopulation__

#include"CChemin.h"
#include"CVille.h"

template <class T> class CPopulation
{
    /*
    Classe représentant une population
    composée de plusieurs chemins
    */
private:
    int mN;
    T* mCPopulation;
public:
    CPopulation();
    CPopulation(T*, int);
    CPopulation(const CPopulation&);
    ~CPopulation();

    CPopulation& operator=(CPopulation&);
    CPopulation& operator+(CPopulation&);

    int get_lenght();
    void Print();

    CChemin<CVille>& operator[](int);
};

void init_pop(CPopulation<CChemin<CVille> >* Pop);

#endif
