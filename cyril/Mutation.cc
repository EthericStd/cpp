#include<ctime>
#include<cstdlib>
#include<iostream>

#include"Mutation.h"

void echange(CChemin<CVille>* Che)
{
    // prend un chemin en paramètre et le mute
    // pour la mutation sur l'exemple deu voyageur de commerce
    // on echange tout simplement 2 villes entre elles
    int N = Che->get_lenght();
    int r1, r2;
    r1 = rand() % N; // on choisi l'indice de la première ville à échanger
    r2 = rand() % N; // on choisi l'indice de la deuxième ville à échanger
    while(r2 == r1)
    {
        r2 = rand() % N;
    }

    // on procède à l'échange
    CVille memo = (*Che)[r1];
    (*Che)[r1] = (*Che)[r2];
    (*Che)[r2] = memo;
}

void Mutation::start(CPopulation< CChemin<CVille> >* Pop)
{
    // fonction principale de la classe


    int N = Pop->get_lenght();
    // boucle que sur tous le chemins de la population
    for(int i=0;i<N;i++)
    {
        echange(&(*Pop)[i]); // prend un chemin en paramètre et le mute
    }
}
