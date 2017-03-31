#ifndef ICHROMOSOME
#define ICHROMOSOME

#include<vector>

using namespace std;

template <class A> class Chromosome
{
    /*
    Classe représentant un chromosome
    composée de plusieurs génes
    */
private:
    int mN;
    vector<A> mChromosome(int);
public:
    Chromosome();
    Chromosome(vector<A>, int);
    Chromosome(const Chromosome&);
    ~Chromosome();

    Chromosome& operator=(Chromosome&);
};

#endif
