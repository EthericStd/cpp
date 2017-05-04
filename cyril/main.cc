#include <iostream>
#include "CVille.h"
#include "CChemin.h"
#include "CPopulation.h"

using namespace std;

int main(void)
{

    cout<<"Ville :"<<endl;
    CVille g1("Toulon"), g2("Toulouse"), g3("Renes"), g4("Bordeau");
    g1.Print();
    g2.Print();
    g3.Print();
    g4.Print();

    /*cout<<"Chemin :"<<endl;
    CVille tg1[2] = {g1, g2};
    CChemin<CVille> c1(tg1, 2);
    c1.Print();
    CVille tg2[2] = {g3, g4};
    CChemin<CVille> c2(tg2, 2);
    c2.Print();

    cout<<"Population"<<endl;
    CChemin<CVille> tc1[2] = {c1, c2};
    CPopulation< CChemin<CVille> > p(tc1, 2);
    p.Print();*/


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
