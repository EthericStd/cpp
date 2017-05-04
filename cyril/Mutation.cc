#include<ctime>
#include<cstdlib>
#include<iostream>

#include"Mutation.h"

void echange(CChemin<CVille>* Che)
{
    int N = Che->get_lenght();
    int r1, r2;
    r1 = rand() % N;
    r2 = rand() % N;
    while(r2 == r1)
    {
        r2 = rand() % N;
    }
    std::cout<<"r: "<<r1<<" "<<r2<<std::endl;

    CVille memo = (*Che)[r1];
    (*Che)[r1] = (*Che)[r2];
    (*Che)[r2] = memo;
}

void Mutation::start(CPopulation< CChemin<CVille> >* Pop)
{
    int N = Pop->get_lenght();
    for(int i=0;i<N;i++)
    {
        echange(&(*Pop)[i]);
    }
}
