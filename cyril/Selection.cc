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
    // retourne un tableau dont l'indice i est égal
    // à la somme des valeurs des indices précédants i
    // dans la tableau en paramètre
    // par exemple si fitness = [1, 2, 3]
    // la tableau retourné sera [1, 1+2, 1+2+3]
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
    // retourne le dernier indice du tableau en paramètre
    float sum = tab[N-1];
    return sum;
}

CPopulation< CChemin<CVille> > Selection::roulette(CPopulation< CChemin<CVille> >& Pop)
{
    //récupère la fitness de chaque chemins dans la tableau fitness
    int N = Pop.get_lenght();
    float fitness[N];
    for(int i=0;i<N;i++)
    {
        fitness[i] = Pop[i].Fitness();
    }

    // cette partie effectue une boucle en mN = le nombre de chemins sélectionnés
    // pour créer le tableau des chemins sélectionnés
    // le principe est la suivant :
    //      - on crée un tableau tab qui est la somme des "indices précédants"
    //      du tableau fitness (voir fonction get_sums)
    //      - on choisi un nombre aléatoire entre 0 et la la dernière valeur de tab
    //      - on regarde chaque valeur de tab dans l'odre croissant des indices
    //      - on retient l'indice de la première valeur trouvée
    //      qui est supérieure au nombre aléatoire choisit
    //      - cet indice sera l'indice du chemin dans la population choisit par la sélection
    //      - on recommence les opérations jusqu'à avoir le nombre de chemins voulu
    //      ( on pense égalament à ne pas choisir 2 fois le même chemin)
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
                    k = N;
                }
        }
    }
    CPopulation< CChemin<CVille> > Pop1(tC ,mN);
    return Pop1;
}
