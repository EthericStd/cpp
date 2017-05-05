#include<iostream>
#include"CPopulation.h"
#include"option.h"

#include<cstdlib>
#include<string>

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

CVille* t_random(CVille* tab, int N)
{
    CVille* t = new CVille[N];
    for(int i=0;i<N;i++)
    {
        t[i] = tab[i];
    }
    int a, b;
    CVille c;
    for(int i=0;i<N*10;i++)
    {
        a = rand() % N;
        b = rand() % N;
        c = t[a];
        t[a] = t[b];
        t[b] = c;
    }
    return t;
}

template <class T>
CChemin<CVille>& CPopulation<T>::operator[](int i)
{
    return mCPopulation[i];
}


void init_pop(CPopulation<CChemin <CVille> >* Pop)
{
    // on crée toutes les villes dans tV
    int N = NB_VILLE;
    CVille tV[N];
    int x, y;
    for(int i=0;i<N;i++)
    {
        x = rand() % MAX_X;
        y = rand() % MAX_Y;
        //tV[i] = CVille(to_string(i), x, y);
        tV[i] = CVille("lol", x, y);
    }

    // on crée tous les chemins dans tC
    int M = NB_CHEMIN;
    CChemin<CVille> tC[M];
    for(int j=0;j<M;j++)
    {
        CVille* t_rand;
        t_rand = t_random(tV, N);
        CChemin<CVille> memo(t_rand, N);
        tC[j] = memo;
        // tC[j].Print();
    }
    CPopulation< CChemin<CVille> > Pop_memo(tC, M);
    (*Pop) = Pop_memo;
}


template <class T>
int CPopulation<T>::get_len()
{
    // for(int i=0;i<mN;i++)
    // {
    //     mCPopulation[i] = pP.mCPopulation[i];
    // }
    cout<<"mN"<<mN<<endl;
}

template class CPopulation< CChemin<CVille> >;
