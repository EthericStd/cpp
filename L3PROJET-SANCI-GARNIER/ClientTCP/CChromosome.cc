#include "CChromosome.h"
#include <iostream>

using namespace std;

int static x=5000; // Variable qui permet d'obtenir des chemins differents, l'initialisation du rand par rapport au temps n'étant pas suffisante sinon. 

//constructeurs

CChromosome::CChromosome(){
    m_length=0;
    m_Path=NULL;
}

CChromosome::CChromosome(int pNbCities){


    m_length=pNbCities;
    m_Path = new int[pNbCities];
    
    for (int i=0;i<pNbCities;i++)
        m_Path[i]=i;
    
    int l_x,l_temp,l_rand;
    
    l_x = rand()%pNbCities;
    l_rand=l_x;
    
    srand(time(NULL)*x);
    
    for (int i=0;i<pNbCities;i++)
    {
        while(l_x==l_rand)
            l_rand=rand()%pNbCities;
        
        l_x=l_rand;
        l_temp=m_Path[l_x];
        m_Path[l_x]=m_Path[i];
        m_Path[i]=l_temp;
    }
    x++;
}

CChromosome::CChromosome(const CChromosome &pCChromosome){ // recopie

    m_length=pCChromosome.m_length;
    
    m_Path = new int[m_length];
    
    for(int i=0;i<m_length;i++)
        m_Path[i]=pCChromosome.m_Path[i];
}

//destructeur

CChromosome::~CChromosome(){
    delete [] m_Path;
}
    
//methodes

void CChromosome::print(){ // afficheur
    
    for(int i=0;i<m_length;i++)
            cout<<m_Path[i]<<" ";
            
    cout<<endl;
}

CChromosome& CChromosome::operator=(const CChromosome &pPath){ // surchargeur

    if(this!=&pPath){
    
        delete[] m_Path;
        m_length=pPath.m_length;
        m_Path=new int[m_length];
        
        for(int i=0;i<m_length;i++)
            m_Path[i]=pPath.m_Path[i];
    }
    
    return *this;
}

int CChromosome::getLength(){ // accesseur qui retourne la longueur du chromosome
    return m_length;
}

int CChromosome::getPath(int i){ // accesseur
    return m_Path[i];
}

int* CChromosome::getmPath(){ // accesseur
    return m_Path;
}

void CChromosome::setPath(int pPos,int pObj){ // accesseur
    m_Path[pPos]=pObj;
}

void CChromosome::setNewChromosome(){ // accesseur

	// cet accesseur permet de changer au complet un chromosome

    CChromosome lp(m_length);
    for (int i=0;i<m_length;i++)
        m_Path[i]=lp.m_Path[i];
}


























