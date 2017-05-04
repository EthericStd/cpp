#ifndef __Mutation__
#define __Mutation__

#include"CPopulation.h"
#include"CChemin.h"
#include"CVille.h"


class Mutation
{
    /*
    Classe servant à faire muter
    une population
    */
private:
    //rien
public:
    //on laisse les constructeur par défaut
    void start(CPopulation< CChemin<CVille> >*);
};

#endif
