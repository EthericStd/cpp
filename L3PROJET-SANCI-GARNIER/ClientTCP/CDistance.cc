#include "CDistance.h"
#include <iostream>
#include <cmath>

using namespace std;

// cette classe est un singleton

//constructeurs

CDistance::CDistance(CGeneList &pList){
	
	// cette classe est un singleton qui sert juste a etre interrogé
	// lors de la définition , les distances sont directement calculées
	// et sont disposées de facon matricielle

    m_Number=pList.getNbGene();
    m_Matrix=new int*[m_Number];
    
    CGene * lListV=pList.getList();
    
    
    for(int i=0;i<m_Number;i++){
        m_Matrix[i]=new int[m_Number];
        for(int j=0;j<m_Number;j++){
            m_Matrix[i][j]=calcDistance(lListV[i],lListV[j]);
        }
    }            
}

CDistance::CDistance(const CDistance &pDist){ // recopie

    m_Number=pDist.m_Number;
    m_Matrix=new int*[m_Number];
    
    for(int i=0;i<m_Number;i++){
        for(int j=0;j<m_Number;j++){
            m_Matrix[i][j]=pDist.m_Matrix[i][j];
        }
    }
}

//destructeur

CDistance::~CDistance(){

	// ce destructeur un peu étrange est la seule solution
	// trouvée face a unprobleme de double free or corruption

    int * lTab = new int[500];
    
    for(int i=0;i<m_Number;i++)
        delete [] m_Matrix[i];
        
    delete [] m_Matrix;
    delete [] lTab;
}

//methode

int CDistance::calcDistance(CGene &v1,CGene &v2){

	// ici on calcule la distance entre 2 ville avec le theoreme de pythagore

    int lx,ly;
    
    lx=abs(v1.getCoordx()-v2.getCoordx());
    ly=abs(v1.getCoordy()-v2.getCoordy());
    
    int lDistance=sqrt((lx*lx)+(ly*ly));
    
    return lDistance;
}

void CDistance::print(){ // afficheur

    for(int i=0;i<m_Number;i++){
    
        for(int j=0;j<m_Number;j++)
            cout<<m_Matrix[i][j]<<" ";
            
        cout<<endl;
    }
}

int CDistance::getDistance(int i,int j){ // accesseur
	
	// vu que les distances sont enregistrées de facon matricielle
	// il suffit de donner deux villes en parametre pour retourner la distance qui les séparent

    return m_Matrix[i][j];
    
}

CDistance& CDistance::operator=(const CDistance &pDist){ // surchargeur
    
    if(this!=&pDist){
        m_Number=pDist.m_Number;
        
        delete [] m_Matrix;
        m_Matrix=new int*[m_Number];
    
        for(int i=0;i<m_Number;i++){
            for(int j=0;j<m_Number;j++){
                m_Matrix[i][j]=pDist.m_Matrix[i][j];
            }
        }
    }
    
    return *this;
}





























