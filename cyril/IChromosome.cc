#include<iostream>
#include"IChromosome.h"

using namespace std;

template <class T>
IChromosome<T>::IChromosome()
{
    mN = 0;
    mIChromosome = 0;
}

template <class T>
IChromosome<T>::IChromosome(T* pIChromosome, int pN)
{
    mN = pN;
    mIChromosome = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mIChromosome[i] = pIChromosome[i];
    }
}

template <class T>
IChromosome<T>::IChromosome(const IChromosome& pC)
{
    mN = pC.mN;
    mIChromosome = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mIChromosome[i] = pC.mIChromosome[i];
    }
}

template <class T>
IChromosome<T>::~IChromosome()
{
    delete [] mIChromosome;
}

template <class T>
IChromosome<T>& IChromosome<T>::operator=(IChromosome<T>& pC)
{
    if (this != &pC)
    {
        mN = pC.mN;
        mIChromosome = new T[mN];
        for(int i=0;i<mN;i++)
        {
            mIChromosome[i] = pC.mIChromosome[i];
        }
    }
return *this;
}

template <class T>
int IChromosome<T>::get_lenght()
{
    return mN;
}

template <class T>
void IChromosome<T>::Print()
{
    for(int i=0;i<mN;i++)
    {
        mIChromosome[i].Print();
    }
}
