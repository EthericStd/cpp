#include<iostream>
#include"IPopulation.h"

using namespace std;

template <class T>
IPopulation<T>::IPopulation()
{
    mN = 0;
    mIPopulation = 0;
}

template <class T>
IPopulation<T>::IPopulation(T* pIPopulation, int pN)
{
    mN = pN;
    mIPopulation = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mIPopulation[i] = pIPopulation[i];
    }
}

template <class T>
IPopulation<T>::IPopulation(const IPopulation<T>& pP)
{
    mN = pP.mN;
    mIPopulation = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mIPopulation[i] = pP.mIPopulation[i];
    }
}

template <class T>
IPopulation<T>::~IPopulation()
{
    delete [] mIPopulation;
}

template <class T>
IPopulation<T>& IPopulation<T>::operator=(IPopulation<T>& pP)
{
    if (this != &pP)
    {
        mN = pP.mN;
        mIPopulation = new T[mN];
        for(int i=0;i<mN;i++)
        {
            mIPopulation[i] = pP.mIPopulation[i];
        }
    }
return *this;
}

template <class T>
int IPopulation<T>::get_lenght()
{
    return mN;
}

template <class T>
void IPopulation<T>::Print()
{
    for(int i=0;i<mN;i++)
    {
        mIPopulation[i].Print();
    }
}
