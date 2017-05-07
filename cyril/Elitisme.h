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
    // nombre de chemins retournés par l'élitisme
    int mN;
public:
    // constructeur
    Elitisme(int);

    // lance l'élitisme
    CPopulation< CChemin<CVille> > start(CPopulation< CChemin<CVille> >&);
};

#endif
