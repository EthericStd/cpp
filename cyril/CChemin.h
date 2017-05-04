#ifndef __CChemin__
#define __CChemin__

#include"CVille.h"
#include <cmath>

template <class T> class CChemin
{
    /*
    Classe représentant un chemin
    composée de plusieurs villes
    */
private:
    int mN;
    T* mCChemin;
public:
    CChemin();
    CChemin(T* , int);
    CChemin(const CChemin&);
    ~CChemin();

    CChemin& operator=(CChemin&);

    int get_lenght();
    void Print();

    CVille& operator[](int);

    float Fitness();
};

#endif
