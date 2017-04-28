#include"CMutation.h"
#include<ctime>
#include<cmath>

Population CMutaion::Mutation(const Population& pop)
{
    srand(time(NULL));
    int rdn = rand() % pop.taille;
    int rdn2 = rand() % taillechem;
    pop[rdn][rdn2] = rand() % matrice.mN;
    return pop;
};
