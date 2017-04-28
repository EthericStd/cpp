#include <iostream>
#include "IGene.h"
#include "IChromosome.h"
#include "IPopulation.h"

using namespace std;

int main(void)
{

    IGene g1("gene1"), g2("gene2"), g3("gene3"), g4("gene4");
    cout<<"Gene :"<<endl;
    g1.Print();
    g2.Print();
    g3.Print();
    g4.Print();

    cout<<"Chromosome :"<<endl;
    IGene tg1[2] = {g1, g2};
    IChromosome<IGene> c1(tg1, 2);
    c1.Print();

    IGene tg2[2] = {g3, g4};
    IChromosome<IGene> c2(tg2, 2);
    c2.Print();


    //IPopulation<IChromosome> p(tc, 3);
    //cout<<"population"<<endl;
    //p.Print();


    /*
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
