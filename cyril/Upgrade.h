#ifndef __Upgrade__
#define __Upgrade__

#include"CPopulation.h"
#include"CChemin.h"
#include"CVille.h"

class Upgrade
{
    /*
    Classe servant à passer la population n
    à la population n+1
    */
private:
    //rien
public:
    void start(CPopulation< CChemin<CVille> >*);
};

#endif
