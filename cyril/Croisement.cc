#include<ctime>
#include<cstdlib>
#include<iostream>

#include"Croisement.h"

int* zeros(int N)
{
    // crée un tableau de N zéros
    int *t = new int[N];
    for(int i=0;i<N;i++)
    {
        t[i] = 0;
    }
    return t;
}

int* random(int* visited, int N)
{
    // retourne un tableau de 2 indices aléatoires
    // on retourne les 2 indeices x et y
    // si et seulement si visited[x] = visited[y] = 0
    int* ran = new int[N];
    int r1, r2;
    r1 = rand() % N;
    while(visited[r1] == 1) r1 = rand() % N;
    r2 = rand() % N;
    while((visited[r2] == 1) || (r2 == r1)) r2 = rand() % N;
    ran[0] = r1;
    ran[1] = r2;
    return ran;
}

void croise(CPopulation< CChemin<CVille> >* Pop)
{
    // prends 2 chemin en paramètre
    // retourne les 2 enfants du croisement de ces 2 chemins
    int N = (*Pop)[0].get_lenght();
    int index = (rand() % (N-1)) + 1;
    CVille t1[N];
    CVille t2[N];
    for(int i=0;i<index;i++)
    {
        t1[i] = (*Pop)[0][i];
        t2[i] = (*Pop)[1][i];
    }
    for(int j=index;j<N;j++)
    {
        t1[j] = (*Pop)[1][j];
        t2[j] = (*Pop)[0][j];
    }
    CChemin<CVille> c1(t1, N);
    CChemin<CVille> c2(t2, N);
    CChemin<CVille> che_memo[2] = {c1, c2};
    CPopulation< CChemin<CVille> > Pop_memo(che_memo, 2);
    (*Pop) = Pop_memo;
}

CPopulation< CChemin<CVille> > Croisement::start(CPopulation< CChemin<CVille> >& Pop)
{
    // fonction lancant le croisement de la population en paramètre
    int N = Pop.get_lenght();
    CChemin<CVille> tC[N];
    int* visited = zeros(N);
    int* ran;

    CPopulation< CChemin<CVille> > Pop1;
    // boucle parcourant la moitié des chemins
    for(int i=0; i<N/2;i++)
    {
        ran = random(visited, N); // on choisi 2 chemins au hasard parmi la population
        CChemin<CVille> che_memo[2] = {Pop[ran[0]],Pop[ran[1]]};
        CPopulation< CChemin<CVille> > Pop_memo(che_memo, 2);
        croise(&Pop_memo); // on croise ces 2 chemins
        Pop1 = Pop1 + Pop_memo; // on ajoute ces 2 chemins dans la nouvelle population
        visited[ran[0]] = 1;
        visited[ran[1]] = 1;
    }

    return Pop1;
}
