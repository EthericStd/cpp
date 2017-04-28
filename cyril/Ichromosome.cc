#include<iostream>

template <class A> Chromosome::Chromosome()
{

}

template <class A> Chromosome::Chromosome()
{
    return name;
}

template <class A> string Chromosome::Chromosome(const& )
{
    mName = pName;
}

template <class A> string Chromosome::Chromosome(pName)
{
    delete [] mChromosome;
}
