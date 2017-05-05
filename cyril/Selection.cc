#include<ctime>
#include<cstdlib>
#include<iostream>

#include"Selection.h"

Selection::Selection(int pN)
{
    mN = pN;
}

float* get_sums(float* fitness, int N)
{
    float* tab = new float[N];
    tab[0] = fitness[0];
    for(int i=1;i<N;i++)
    {
        tab[i] = tab[i-1] + fitness[i];
    }
    return tab;
}

float get_sum(float* tab, int N)
{
    float sum;
    for(int i=0;i<N;i++)
    {
        sum += tab[i];
    }
    return sum;
}

CPopulation< CChemin<CVille> > Selection::roulette(CPopulation< CChemin<CVille> >& Pop)
{
    //récupère la fitness (plus grand = mieux)
    int N = Pop.get_lenght();
    float fitness[N];
    for(int i=0;i<N;i++)
    {
        fitness[i] = Pop[i].Fitness();
    }

    CChemin<CVille> tC[mN];
    float* tab = get_sums(fitness, N);
    float sum = get_sum(tab, N);
    float ran = (((float) rand()) / ((float) RAND_MAX)) * sum;
    for(int j=0;j<mN;j++)
    {
        for(int k=0;k<N;k++)
        {
            if(ran < tab[k])
                {
                    tC[j] = Pop[k];
                    fitness[k] = 0;
                    tab = get_sums(fitness, N);
                    sum = get_sum(tab, N);
                    ran = (((float) rand()) / ((float) RAND_MAX)) * sum;
                    cout<<1<<endl;
                }
        }
        cout<<2<<endl;
    }
    CPopulation< CChemin<CVille> > Pop1(tC ,mN);
    return Pop1;
}
