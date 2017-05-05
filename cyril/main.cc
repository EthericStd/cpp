#include <iostream>
#include "CVille.h"
#include "CChemin.h"
#include "CPopulation.h"
#include "Mutation.h"
#include "cng.h"
#include "Elitisme.h"
#include "Selection.h"
#include "Croisement.h"

#define MAX_ITER


#include<ctime>
#include<cstdlib>

/*void print_pop()
{

}

void dessin(void)
{
    if(cpt < MAX_ITER)
    {
    print_pop()

    Cpopulation pop, pop1;
    pop = matriceville.init(pop);
    elitisme
    selection et croisement
    mutation

    usleep(10000);
    cng_swap_screen();
    cng_clear_screen();
    }
}*/

using namespace std;

int main(int argc, char** argv)
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
    // CPopulation< CChemin<CVille> > p(C, 2);
    p.Print();

    cout<<"Fitness 1:"<<c1.Fitness()<<endl;
    cout<<"Fitness 2:"<<c2.Fitness()<<endl;*/

    CVille V4[4] = {v1, v2, v3, v4};
    CChemin<CVille> c3(V4, 4);
    CChemin<CVille> C1[2] = {c3, c3};
    CPopulation< CChemin<CVille> > p1(C1, 2);

    // p1.Print();
    // Mutation Mut;
    // Mut.start(&p1);
    // p1.Print();

    // p1.Print();
    Elitisme Eli(1);
    CPopulation< CChemin<CVille> > p2 = Eli.start(p1);
    // p2.Print();

    CPopulation< CChemin<CVille> > p3;
    p3 = p1 + p1;
    // cout<<"AH"<<endl;
    // p3.Print();

    // cout<<"AH"<<endl;
    Selection Sel(2);
    CPopulation< CChemin<CVille> > p4 = Sel.roulette(p3);
    // p4.Print();

    Croisement Cro;
    CPopulation< CChemin<CVille> > p5 = Cro.start(p3);

    CPopulation< CChemin<CVille> > Pop_memo;
    Pop_memo = p3;
    cout<<"test Pop_memo"<<endl;
    // Pop_memo.Print();

    // char titre[35] = "Le voyageur de commerce";
    // cng_init_window(&argc, argv, titre, 1200, 675);
    // cng_display_func(dessin);
    // cng_clear_screen();
    // cng_main_loop();
    // cng_destroy_window();

    return 0;

}
