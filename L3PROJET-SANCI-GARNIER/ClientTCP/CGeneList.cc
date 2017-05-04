#include "CGeneList.h"
#include <iostream>

using namespace std;

//Constructeur

CGeneList::CGeneList(){
    m_List=NULL;
    m_NbGene=0;
}

CGeneList::CGeneList(const int pNbGene){
    
    m_NbGene=pNbGene;
    m_List = new CGene[pNbGene];
    
    for(int i=0;i<pNbGene;i++){
        m_List[i]=CGene(i);
    }
}

CGeneList::CGeneList(const CGeneList &pTW){
    m_NbGene=pTW.m_NbGene;
    
    m_List=new CGene[m_NbGene];
    
    for(int i=0;i<m_NbGene;i++)
        m_List[i]=pTW.m_List[i];
}

//Destructeur

CGeneList::~CGeneList(){
    delete [] m_List;
}

//Methodes

void CGeneList::print(){ // afficheur
    
    for(int i=0;i<m_NbGene;i++){
        cout<<"Ville n°"<<m_List[i].getNum()<<"; x="<<m_List[i].getCoordx()<<"    y="<<m_List[i].getCoordy()<<endl;
    }
}

int CGeneList::getNbGene(){
    return m_NbGene;
}

CGene* CGeneList::getList(){
    return m_List;
}

CGene CGeneList::getGene(int i){
    return m_List[i];
}

CGeneList& CGeneList::operator=(const CGeneList &pTW){
    if(this!=&pTW){
        m_NbGene=pTW.m_NbGene;
        
        delete [] m_List;
        m_List=new CGene[m_NbGene];
        
        for(int i=0;i<m_NbGene;i++)
            m_List[i]=pTW.m_List[i];
    }
    
    return *this;
}














