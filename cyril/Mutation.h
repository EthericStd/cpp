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
    // lance la mutation
    void start(CPopulation< CChemin<CVille> >*);
};

#endif
