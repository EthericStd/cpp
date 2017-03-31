#ifndef IPOPULATION
#define IPOPULATION

template <class A> class Population
{
    /*
    Classe représentant une population
    composée de plusieurs chromosomes
    */
private:
    int mN;
    vector<A> mPopulation(int);
public:
    Population();
    Population(vector<A>, int);
    Population(const Population&);
    ~Population();

    Population& operator=(Population&);
};

#endif
