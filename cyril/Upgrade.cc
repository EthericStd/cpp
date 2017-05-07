#include<iostream>
#include"Upgrade.h"
#include"option.h"

#include "Mutation.h"
#include "Elitisme.h"
#include "Selection.h"
#include "Croisement.h"

using namespace std;

// on définit les classe utiles globalement
// pour éviter de les recréer à achque appel
Mutation Mut;
Croisement Cro;
Selection Sel(NB_SELECTION);
Elitisme Eli(NB_Elitiste);

void Upgrade::start(CPopulation< CChemin<CVille> >* Pop)
{
    // change directement la population passé par adresse
    CPopulation< CChemin<CVille> > Pop_elitiste = Eli.start(*Pop); // Elitisme
    CPopulation< CChemin<CVille> > Pop_select = Sel.roulette(*Pop); // Sélection
    CPopulation< CChemin<CVille> > Pop_croisement = Cro.start(Pop_select); // Croisement
    Mut.start(&Pop_croisement); // Mutation
    (*Pop) = Pop_elitiste + Pop_croisement; // affectation de la nouvelle population
}
