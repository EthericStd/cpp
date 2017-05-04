#ifndef IPOPULATION
#define IPOPULATION

#include"CChemin.h"

template <class T> class IPopulation
{
    /*
    Classe représentant une Ipopulation
    composée de plusieurs chromosomes
    */
private:
    int mN;
    T* mIPopulation;
public:
    IPopulation();
    IPopulation(T*, int);
    IPopulation(const IPopulation&);
    ~IPopulation();

    IPopulation& operator=(IPopulation&);

    int get_lenght();
    void Print();
};

#endif
