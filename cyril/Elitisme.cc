#include<ctime>
#include<cstdlib>
#include<iostream>

#include"Elitisme.h"

Elitisme::Elitisme(int pN)
{
    mN = pN;
}

int get_max(float* t, int N)
{
    float max = t[0];
    int index = 0;
    for(int i=1;i<N;i++)
    {
        if(t[i] > max)
        {
            max = t[i];
            index = i;
        }
    }
    return index;
}

CPopulation< CChemin<CVille> > Elitisme::start(CPopulation< CChemin<CVille> >& Pop)
{
    //récupère la fitness (plus grand = mieux)
    int N = Pop.get_lenght();
    float t[N];
    for(int i=0;i<N;i++)
    {
        t[i] = Pop[i].Fitness();
    }

    //crée le tableau des indices a récupérer
    int index;
    CChemin<CVille> tC[mN];
    for(int j=0;j<mN;j++)
    {
        index = get_max(t, N);
        tC[j] = Pop[index];
        t[index] = 1<<16;
    }
    CPopulation< CChemin<CVille> > Pop1(tC ,mN);
    return Pop1;
}
