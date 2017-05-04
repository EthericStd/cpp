#ifndef CPopulation
#define CPopulation

#include"CChemin.h"

template <class T> class CPopulation
{
    /*
    Classe représentant une CPopulation
    composée de plusieurs chromosomes
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

    int get_lenght();
    void Print();
};

#endif
