#include<iostream>
#include"Upgrade.h"
#include"option.h"

#include "Mutation.h"
#include "Elitisme.h"
#include "Selection.h"
#include "Croisement.h"

using namespace std;

void Upgrade::start(CPopulation< CChemin<CVille> >* Pop)
{
    Elitisme Eli(NB_Elitiste);
    CPopulation< CChemin<CVille> > Pop_elitiste = Eli.start(*Pop);
    Selection Sel(NB_SELECTION);
    CPopulation< CChemin<CVille> > Pop_select = Sel.roulette(*Pop);
    Croisement Cro;
    CPopulation< CChemin<CVille> > Pop_croisement = Cro.start(Pop_select);
    
    (*Pop) = Pop_elitiste + Pop_croisement;

}
