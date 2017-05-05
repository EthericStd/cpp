#ifndef __Elitisme__
#define __Elitisme__

#include"CPopulation.h"
#include"CChemin.h"
#include"CVille.h"


class Elitisme
{
    /*
    Classe retournant les meilleurs chemins
    */
private:
    int mN;
public:
    Elitisme(int);
    CPopulation< CChemin<CVille> > start(CPopulation< CChemin<CVille> >&);
};

#endif
