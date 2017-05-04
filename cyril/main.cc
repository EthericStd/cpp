#include <iostream>
#include "CVille.h"
#include "CChemin.h"
#include "CPopulation.h"
#include "Mutation.h"


#include<ctime>
#include<cstdlib>


using namespace std;

int main(void)
{
    srand(time(NULL));

    
    //TESTS
    CVille v1("Toulon", 0, 1), v2("Toulouse", 0, 5), v3("Renes", 1, 3), v4("Bordeau", 0, 4);
    /*v1.Print();
    v2.Print();
    v3.Print();
    v4.Print();

    CVille V1[2] = {v1, v2};
    CChemin<CVille> c1(V1, 2);
    c1.Print();
    CVille V2[2] = {v3, v4};
    CChemin<CVille> c2(V2, 2);
    c2.Print();

    CChemin<CVille> C[2] = {c1, c2};
    CPopulation< CChemin<CVille> > p(C, 2);
    p.Print();

    cout<<"Fitness 1:"<<c1.Fitness()<<endl;
    cout<<"Fitness 2:"<<c2.Fitness()<<endl;*/

    CVille V4[4] = {v1, v2, v3, v4};
    CChemin<CVille> c3(V4, 4);
    CChemin<CVille> C1[2] = {c3, c3};
    CPopulation< CChemin<CVille> > p1(C1, 2);

    p1.Print();
    Mutation Mut;
    Mut.start(&p1);
    p1.Print();

/*
    //DEBUT
    //--initialisation
    Cpopulation pop, pop1;
    pop = matriceville.init(pop);

    //--boucle principale
    int i, max=100;
    for(i=0;i<max;i++)
    {
        elitisme
        selection et croisement
        mutation
    }
    */

    return 0;

}
