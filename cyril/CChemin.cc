#include<iostream>
#include"CChemin.h"
#include"option.h"

using namespace std;

template <class T>
CChemin<T>::CChemin()
{
    mN = 0;
    mCChemin = 0;
}

template <class T>
CChemin<T>::CChemin(T* pCChemin, int pN)
{
    mN = pN;
    mCChemin = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mCChemin[i] = pCChemin[i];
    }
}

template <class T>
CChemin<T>::CChemin(const CChemin& pC)
{
    mN = pC.mN;
    mCChemin = new T[mN];
    for(int i=0;i<mN;i++)
    {
        mCChemin[i] = pC.mCChemin[i];
    }
}

template <class T>
CChemin<T>::~CChemin()
{
    delete [] mCChemin;
}

template <class T>
CChemin<T>& CChemin<T>::operator=(CChemin<T>& pC)
{
    if (this != &pC)
    {
        mN = pC.mN;
        mCChemin = new T[mN];
        for(int i=0;i<mN;i++)
        {
            mCChemin[i] = pC.mCChemin[i];
        }
    }
return *this;
}

template <class T>
int CChemin<T>::get_lenght()
{
    return mN;
}

template <class T>
void CChemin<T>::Print()
{
    cout<<"Chemin: "<<endl;
    for(int i=0;i<mN;i++)
    {
        mCChemin[i].Print();
    }
}

template <class T>
CVille& CChemin<T>::operator[](int i)
{
    return mCChemin[i];
}

template <class T>
float CChemin<T>::Fitness()
{
    // fonction retournant la Fitness d'un chemin
    // la Fitness est calculée par rapport à la Fitness du pire chemin possible
    float worst_fitness = sqrt(pow(MAX_X,2) + pow(MAX_Y,2));
    float x, y, res = 0;
    for(int i=0;i<mN-1;i++)
    {
        x = mCChemin[i+1].get_x() - mCChemin[i].get_x();
        y = mCChemin[i+1].get_y() - mCChemin[i].get_y();
        res += sqrt(pow(x,2) + pow(y,2));
        res = worst_fitness / res;
    }
    return res;
}

template class CChemin<CVille>;
