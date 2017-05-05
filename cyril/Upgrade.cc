#include<iostream>
#include"Upgrade.h"
#include"option.h"

#include "Mutation.h"
#include "Elitisme.h"
#include "Selection.h"
#include "Croisement.h"

using namespace std;


Mutation Mut;
Croisement Cro;
Selection Sel(NB_SELECTION);
Elitisme Eli(NB_Elitiste);

void Upgrade::start(CPopulation< CChemin<CVille> >* Pop)
{
    CPopulation< CChemin<CVille> > Pop_elitiste = Eli.start(*Pop);
    // cout<<"eli "<<endl;
    // Pop_elitiste.get_len();
    CPopulation< CChemin<CVille> > Pop_select = Sel.roulette(*Pop);
    // cout<<"sel "<<endl;
    // Pop_select.get_len();
    CPopulation< CChemin<CVille> > Pop_croisement = Cro.start(Pop_select);
    // cout<<"cro "<<endl;
    // Pop_croisement.get_len();
    Mut.start(&Pop_croisement);
    // cout<<"mut "<<endl;
    // Pop_croisement.get_len();
    (*Pop) = Pop_elitiste + Pop_croisement;
    // cout<<"pop "<<endl;
    // Pop->get_len();
}
