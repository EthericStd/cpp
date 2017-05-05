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
    int mN;
public:
    Selection(int);
    CPopulation< CChemin<CVille> > roulette(CPopulation< CChemin<CVille> >&);
    // CPopulation< CChemin<CVille> > rang(CPopulation< CChemin<CVille> >&);
    // CPopulation< CChemin<CVille> > rang(CPopulation< CChemin<CVille> >&);
    // CPopulation< CChemin<CVille> > rang(CPopulation< CChemin<CVille> >&);
};

#endif
