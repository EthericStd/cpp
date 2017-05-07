#include <iostream>
#include "CVille.h"
#include "CChemin.h"
#include "CPopulation.h"
#include "Mutation.h"
#include "cng.h"
#include "Elitisme.h"
#include "Selection.h"
#include "Croisement.h"
#include "Upgrade.h"

#include "option.h"


#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<string>

using namespace std;

// variables globales
int cpt = 0; // compteur de génération
CPopulation< CChemin<CVille> > Pop; // Population
Upgrade Upg; // Classe servant à améliorer une population

void print_pop(CPopulation< CChemin<CVille> > Pop)
{
    // fonction affichant sur l'écran
    // le meilleur chemin de chaque population
    for(int i=0;i<NB_CHEMIN;i++)
    {
        Elitisme Eli1(1);
        CPopulation< CChemin<CVille> > One = Eli1.start(Pop);

        int x, y, x1, y1;
        x = One[0][0].get_x()*FACTOR_X;
        y = One[0][0].get_y()*FACTOR_Y;
        cng_current_color(255, 0, 0);
        cng_circle(x, y, 5);

        string s = to_string(One[0].Fitness());
        char const* pchar = s.c_str();
        char const* txt = "Fitness du meilleur de la generation :";
        cng_current_color(0, 255, 0);
        cng_draw_string(txt, 10, 28);
        cng_draw_string(pchar, 220, 28);
        for(int j=1;j<NB_VILLE;j++)
        {
            x1 = One[0][j].get_x()*FACTOR_X;
            y1 = One[0][j].get_y()*FACTOR_Y;
            cng_current_color(255, 0, 0);
            cng_circle(x1, y1, 5);

            cng_current_color(0, 0, 255);
            cng_line(x, y, x1, y1);
            x = x1;
            y = y1;
        }
    }
}

void print_infos()
{
    // fonction affichant à l'écran le compteur de génération
    string s = to_string(cpt);
    char const* pchar = s.c_str();
    char const* txt = "Generation :";
    cng_current_color(0, 255, 0);
    cng_draw_string(txt, 10, 15);
    cng_draw_string(pchar, 80, 15);
}


void dessin(void)
{
    // fonction principale, récurssive, servant à l'affichage
    // et à lancer l'amélioration de la population
    if(cpt < MAX_ITER)
    {
    // on affiche à l'écran le meilleur chemin de la population
    print_pop(Pop);

    //on améliore la population
    Upg.start(&Pop);

    // affichage d'informations
    print_infos();

    // on met la programme en pause quelques milisecondes
    usleep(10000);

    // on efface l'écran
    cng_swap_screen();
    cng_clear_screen();
    cpt ++;
    }
}


int main(int argc, char** argv)
{
    // Pour un aléatoire différent sur chaque éxécution
    srand(time(NULL));

    // initialisation de la population
    // avec des villes placées aléatoirement
    init_pop(&Pop);

    // initialisation et lancement
    // de la fenetre graphique
    char titre[35] = "Le voyageur de commerce";
    cng_init_window(&argc, argv, titre, 1200, 675);
    cng_display_func(dessin);
    cng_clear_screen();
    cng_main_loop();
    cng_destroy_window();

    return 0;

}
