#ifndef __Croisement__
#define __Croisement__

#include"CPopulation.h"
#include"CChemin.h"
#include"CVille.h"


class Croisement
{
    /*
    Classe retournant les meilleurs chemins
    */
private:
    //rien
public:
    CPopulation< CChemin<CVille> > start(CPopulation< CChemin<CVille> >&);
};

#endif
