#include "CElite.h"
#include <iostream>

using namespace std;

int x=5000;

//constructeur

CElite::CElite(int pPerCent,CPossiblePath &pList,CDistance &pDist){

	// ce constructeur prend en parametre une classe d'individus, trouve les meilleurs genes et enregistre leur position
	

    float lLong=pList.getNbPath(); // on calcule le nombre de genes élites on diot garder
    lLong /= 100;
    lLong *= pPerCent;
    m_length=lLong;

    m_ChromosomeElite=new int[m_length]; // liste d'indices des meilleurs chemins

    int lLong2=pList.getNbPath();

    int *l_elite; // liste qui contient la totalité des élites
    l_elite=new int [lLong2];

    int *lIndex; // liste d'indices des meilleurs chemins 
    lIndex=new int [lLong2];

    for(int i=0;i<lLong2;i++)    
        lIndex[i]=i;

    for(int i=0;i<lLong2;i++) // on enregistre les totaux des élites
        l_elite[i]=fitness(pList.getList(i),pDist);
    
    int lTemp;
    int lCpt=0;
    
    while(lCpt<lLong2){ // On trie cette liste pour que l'élite des élites soit le 1er element.
    
        for(int i=0;i<lLong2-1;i++){
        
            if(l_elite[i]>l_elite[i+1]){
            
                lTemp=l_elite[i];
                l_elite[i]=l_elite[i+1];
                l_elite[i+1]=lTemp;
                
                lTemp=lIndex[i];
                lIndex[i]=lIndex[i+1];
                lIndex[i+1]=lTemp;
            }
        }
        lCpt++;
    }
    
    for(int i=0;i<m_length;i++){
        m_ChromosomeElite[i]=lIndex[i];
    }
}

//destructeur

CElite::~CElite(){    
    delete [] m_ChromosomeElite;
}

//fonctions

int CElite::fitness(CChromosome &pPath,CDistance &pDist){

	// cette fonction calcule la fitness des genes
	
    int lTot=0;

    for(int i=1;i<pPath.getLength();i++){
        lTot+=pDist.getDistance(pPath.getPath(i-1),pPath.getPath(i));
    }
    
    lTot+=pDist.getDistance(pPath.getPath(0),pPath.getPath(pPath.getLength()-1));
    
    return lTot;
}

void CElite::mute(CPossiblePath &pCpl,CDistance &pDist){

	// cette fonction mute les meilleurs gènes, uniquement si cette mutation est bénéfique 

    int lTemp1,lTemp2;
    int position1;
    int position2;
    int lTot1,lTot2;
    
    for(int i=0;i<m_length;i++){ 
        
        srand(time(NULL)*x); // Mutation aléatoire
        x++;
        
        position1=rand()%pCpl.getList(0).getLength();
        srand(time(NULL)*x);
        x++;
        
        position2=rand()%pCpl.getList(0).getLength();
        srand(time(NULL)*x);
        x++;
        
        while(position1==position2)
            position2=rand()%pCpl.getList(0).getLength();
        
        lTemp1=pCpl.getList(m_ChromosomeElite[i]).getPath(position1);
        lTemp2=pCpl.getList(m_ChromosomeElite[i]).getPath(position2);
        
        lTot1=fitness(pCpl.getList(i),pDist); // ce total verifie la taille avant mutation
        
        
        
        pCpl.setPathList(m_ChromosomeElite[i],position1,lTemp2);
        pCpl.setPathList(m_ChromosomeElite[i],position2,lTemp1);
        
        lTot2=fitness(pCpl.getList(i),pDist);
        
        if(lTot2>lTot1){ // c'est ici qu'on verifie que la mutation est benefique
       
        
            lTemp1=pCpl.getList(m_ChromosomeElite[i]).getPath(position1);
            lTemp2=pCpl.getList(m_ChromosomeElite[i]).getPath(position2);
        
            pCpl.setPathList(m_ChromosomeElite[i],position1,lTemp2);
            pCpl.setPathList(m_ChromosomeElite[i],position2,lTemp1);
        
        }
    }
}

void CElite::injection(CPossiblePath &pCpl){ 
	
	//On injecte les élites dans un nouvel individu
	// les genes manquants seront calculés aleatoirement

    int l_elite=0;
    
    for(int i=0;i<pCpl.getNbPath();i++){
        l_elite=0;
        
        for(int j=0;j<m_length;j++){
        
            if(i==m_ChromosomeElite[j])
                l_elite=1;
        }
        
        if (l_elite==0)
            pCpl.setNewPath(i);
    }
}

void CElite::crossing(CPossiblePath &pCpl,CDistance &pDist){

	// cette fonction permet de permuter des éléments entre deux genes
	// de la nouvelle instance, pour que la nouvelle instance profite des bienfaits
	// des élites, on aura des problemes de doublons, et on les traitera de la maniere suivante :
	// on supprime les doublons, on vérifie si apres suppression le gene est meilleur
	// s'il n'est pas meilleur, on annule la permutation et on passe au second couple a traiter
    
    int lnbTown=pCpl.getList(0).getLength();
    
    srand(time(NULL)*x);
    x++;
    
    // on choisi aléatoirement combien de genes a permuter
    
    int lnbCross=(rand()%(lnbTown/2))+lnbTown-1;
    
    int lTemp1,lTemp2;
    int lTot1,lTot2,lTot3,lTot4;
    
    // on declare 2 instances pour sauvegarder le couple que l'on va traiter
    
    CChromosome tempPath1,tempPath2;
    
    int lLength=pCpl.getList(0).getLength();
    
    int *lList;
    lList=new int[lLength];
    for(int i=0;i<lLength;i++)
        lList[i]=0;

    int lTemp,lStock=-1,lStock2=-1,lindex;
    
    for(int i=0;i<pCpl.getNbPath()-2;i+=2){ // debut de la permutation
    
        tempPath1=pCpl.getList(i); // sauvegarde
        tempPath2=pCpl.getList(i+1);
        
        lTot1=fitness(pCpl.getList(i),pDist); // évaluation du couple
        lTot3=fitness(pCpl.getList(i+1),pDist);
    
        for(int j=lnbCross;j<lnbTown;j++){ // permutation
        	
            lTemp1=pCpl.getList(i).getPath(j);
            lTemp2=pCpl.getList(i+1).getPath(j);
            pCpl.setPathList(i,j,lTemp2);
            pCpl.setPathList(i+1,j,lTemp1);
        }
    
        for(int l=0;l<pCpl.getNbPath();l++){ // traitement des doublons
    
            for(int j=0;j<lLength;j++){
                lTemp=pCpl.getList(l).getPath(j);
                lList[lTemp]+=1;
            }

            for(int j=0;j<lLength;j++){
        
                if(lList[j]==0 && lStock==-1){
                    lStock=j;
                    j=0;
                }
            
                else if(lList[j]>1 && lStock2 ==-1){
                    lStock2=j;
                    j=0;
                }
                if (lStock2 != -1 && lStock != -1){
                
                    for (int k=0;k<lLength;k++)
                        if (pCpl.getList(l).getPath(k)==lStock2)
                            lindex=k;
                            
                    pCpl.setPathList(l,lindex,lStock);
                    lList[lStock2]-=1;
                    j=0;
                    lList[lStock]+=1;
                    lStock=-1;
                    lStock2=-1;
                }
            }    

            for(int j=0;j<lLength;j++)
                lList[j]=0;
        }

        lTot2=fitness(pCpl.getList(i),pDist); // évaluation apres traitement des doublons
        lTot4=fitness(pCpl.getList(i+1),pDist);
        
        if(lTot2>lTot1){ // si il y a régression dans le premier gene, on annule les changements
        
            for(int k=0;k<lnbCross;k++){
            
                lTemp1=tempPath1.getPath(k);
                pCpl.setPathList(i,k,lTemp1);    
            }
        }
        
        if(lTot4>lTot3){ // si il y a régression dans le second gene, on annule les changements
        	// en effet il pourrait y avoir un meilleur chemin dans ce second gene
        
            for(int k=0;k<lnbCross;k++){
            
                lTemp1=tempPath2.getPath(k);
                pCpl.setPathList(i+1,k,lTemp1);    
            }
        }
    }
}

int CElite::getPathElite(int i){ // accesseur

return m_ChromosomeElite[i];

}

int CElite::getLength(){ // accesseur

return m_length;

}

















