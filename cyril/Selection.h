#ifndef __Selection__
#define __Selection__

#include"CPopulation.h"
#include"CChemin.h"
#include"CVille.h"


class Selection
{
    /*
    Classe retournant les meilleurs chemins
    */
private:
    // nombre de chemins retournés par la sélection
    int mN;
public:
    // contructeur
    Selection(int);

    // sélection par roulette
    CPopulation< CChemin<CVille> > roulette(CPopulation< CChemin<CVille> >&);
    // CPopulation< CChemin<CVille> > rang(CPopulation< CChemin<CVille> >&); // non fait
    // CPopulation< CChemin<CVille> > tounoi(CPopulation< CChemin<CVille> >&); // non fait
    // CPopulation< CChemin<CVille> > uniforme(CPopulation< CChemin<CVille> >&); // non fait
};

#endif
