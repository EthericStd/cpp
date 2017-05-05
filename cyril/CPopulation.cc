#include<iostream>
#include"CPopulation.h"

using namespace std;

template <class T>
CPopulation<T>::CPopulation()
{
    mN = 0;
    mCPopulation = 0;
}

template <class T>
CPopulation<T>::CPopulation(T* pCPopulation, int pN)
{
    mN = pN;
    mCPopulation = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mCPopulation[i] = pCPopulation[i];
    }
}

template <class T>
CPopulation<T>::CPopulation(const CPopulation<T>& pP)
{
    mN = pP.mN;
    mCPopulation = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mCPopulation[i] = pP.mCPopulation[i];
    }
}

template <class T>
CPopulation<T>::~CPopulation()
{
    delete [] mCPopulation;
}

template <class T>
CPopulation<T>& CPopulation<T>::operator=(CPopulation<T>& pP)
{
    if (this != &pP)
    {
        mN = pP.mN;
        mCPopulation = new T[mN];
        for(int i=0;i<mN;i++)
        {
            mCPopulation[i] = pP.mCPopulation[i];
        }
    }
return *this;
}

template <class T>
CPopulation<T>& CPopulation<T>::operator+(CPopulation<T>& pP)
{
    int mN2 = mN + pP.mN;
    T* mCPopulation2 = new T[mN2];
    for(int i=0;i<mN2;i++)
    {
        if(i < mN) mCPopulation2[i] = mCPopulation[i];
        else mCPopulation2[i] = pP.mCPopulation[i-mN];
    }
    mN = mN2;
    mCPopulation = mCPopulation2;
return *this;
}

template <class T>
int CPopulation<T>::get_lenght()
{
    return mN;
}

template <class T>
void CPopulation<T>::Print()
{
    cout<<"Population :"<<endl;
    for(int i=0;i<mN;i++)
    {
        mCPopulation[i].Print();
    }
}

template <class T>
CChemin<CVille>& CPopulation<T>::operator[](int i)
{
    return mCPopulation[i];
}

template class CPopulation< CChemin<CVille> >;
