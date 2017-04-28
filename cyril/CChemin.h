#include"chromosome.h"

class Chemin : public Chromosome
{
    /*
    Classe représentant un chromosome
    composée de plusieurs génes
    */
private:

public:
    // a revoir <Ville>
    Chemin()
    Chemin(Ville* v, int n)
    Chemin(const Chromosome&);
    ~Chemin();

    Chromosome& operator=(Chromosome&);
}
