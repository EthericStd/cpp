#include "CPossiblePath.h"
#include <iostream>

using namespace std;

//constructeur

CPossiblePath::CPossiblePath(int pNb){

    m_NbPath=pNb;
    
    m_ListPath=new CChromosome[m_NbPath];
}

CPossiblePath::CPossiblePath(int pNb,int pNbVilles){

	// crée une liste de chemins (construits au hasard lors de leur initialisation dans la classe chromosome)
	
    m_NbPath=pNb;
    
    m_ListPath=new CChromosome[m_NbPath];
    
    for(int i=0;i<m_NbPath;i++)
        m_ListPath[i]=CChromosome(pNbVilles);
}

CPossiblePath::CPossiblePath(const CPossiblePath &pCChromosome){ // recopie
    m_NbPath=pCChromosome.m_NbPath;
    
    for(int i=0;i<m_NbPath;i++)
        m_ListPath[i]=pCChromosome.m_ListPath[i];
}

//destructeur

CPossiblePath::~CPossiblePath(){ // destructeur

    delete [] m_ListPath;
    
}

//methode

void CPossiblePath::print(){ // afficheur
    
    for(int i=0;i<m_NbPath;i++)
        m_ListPath[i].print();
}

int CPossiblePath::getNbPath(){ // accesseur

    return m_NbPath;
    
}

CChromosome& CPossiblePath::getList(int i){ // accesseur

    return m_ListPath[i];
    
}

CPossiblePath& CPossiblePath::operator=(const CPossiblePath &pPL){ // surchargeur
    if(this!=&pPL){
    
        m_NbPath=pPL.m_NbPath;
        
        delete [] m_ListPath;
        m_ListPath=new CChromosome[m_NbPath];
        
        for(int i=0;i<m_NbPath;i++)
            m_ListPath[i]=pPL.m_ListPath[i];
    }
    
    return *this;
}

void CPossiblePath::setPathList(int pPath,int pPos,int pObj){ // accesseur

    m_ListPath[pPath].setPath(pPos,pObj);
    
}

void CPossiblePath::setNewPath(int pNumPath){ // accesseur

    m_ListPath[pNumPath].setNewChromosome();
    
}






















