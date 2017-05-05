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

int cpt = 0;
CPopulation< CChemin<CVille> > Pop;
Upgrade Upg;

void print_pop(CPopulation< CChemin<CVille> > Pop)
{
    for(int i=0;i<NB_CHEMIN;i++)
    {
        Elitisme Eli1(1);
        CPopulation< CChemin<CVille> > One = Eli1.start(Pop);

        int x, y, x1, y1;
        x = One[0][0].get_x()*FACTOR_X;
        y = One[0][0].get_y()*FACTOR_Y;
        cng_current_color(255, 0, 0);
        cng_circle(x, y, 5);
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
    string s = to_string(cpt);
    char const* pchar = s.c_str();
    char const* txt = "Generation:";
    cng_current_color(0, 255, 0);
    cng_draw_string(txt, 10, 10);
    cng_draw_string(pchar, 100, 10);
}


void dessin(void)
{
    if(cpt < MAX_ITER)
    {

    print_pop(Pop);

    Upg.start(&Pop);

    print_infos();

    usleep(10000);
    cng_swap_screen();
    cng_clear_screen();
    cpt ++;
    }
}


int main(int argc, char** argv)
{
    srand(time(NULL));
    // Pop.Print();
    init_pop(&Pop);
    // Pop.Print();

    char titre[35] = "Le voyageur de commerce";
    cng_init_window(&argc, argv, titre, 1200, 675);
    cng_display_func(dessin);
    cng_clear_screen();
    cng_main_loop();
    cng_destroy_window();

    return 0;

}
