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
    // nombre de chemins
    int mN;
    // tableau des chemins
    T* mCPopulation;
public:
    // constructeurs et destructeur
    CPopulation();
    CPopulation(T*, int);
    CPopulation(const CPopulation&);
    ~CPopulation();

    // surchage d'opérateurs
    CPopulation& operator=(CPopulation&);
    CPopulation& operator+(CPopulation&);
    CChemin<CVille>& operator[](int);

    // retourne la nombre de chemins (pour tests)
    int get_lenght();
    // affiche sur le terminal la population (pour tests)
    void Print();
};

// fonction initiant une population
// avec des villes placées aléatoirement
void init_pop(CPopulation<CChemin<CVille> >* Pop);

#endif
