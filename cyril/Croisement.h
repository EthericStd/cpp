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
    // rien
public:
    // fonction lancant le croisement
    // retourne la nouvelle population d'enfants
    // contenant le même nombre de chemins
    CPopulation< CChemin<CVille> > start(CPopulation< CChemin<CVille> >&);
};

#endif
