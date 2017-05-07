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
    // nombre de villes
    int mN;
    // tableau des villes
    T* mCChemin;
public:
    // constructeurs et destructeur
    CChemin();
    CChemin(T* , int);
    CChemin(const CChemin&);
    ~CChemin();

    // surchage d'opérateurs
    CChemin& operator=(CChemin&);
    CVille& operator[](int);

    // retourne la nombre de chemins (pour tests)
    int get_lenght();
    // affiche sur le terminal la population (pour tests)
    void Print();

    // fonction retournant un flotant qui représente
    // la Fitness d'un chemin
    float Fitness();
};

#endif
