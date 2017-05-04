#ifndef ____CDistance____
#define ____CDistance____

#include "CGeneList.h"

// cette classe est un singleton

class CDistance{
private:
    
    int ** m_Matrix; //Matrice qui contient toutes les distances qui séparent chaques villes
    int m_Number;
        
public:
    
        //constructeurs
        
    CDistance(CGeneList&); // constructeur le plus utilisé
    CDistance(const CDistance&); // constructeur par recopie
        
        //destructeur
        
    ~CDistance();
        
        //methode
        
    void print(); // afficheur
    int calcDistance(CGene&,CGene&); // calcule la distance en 2 genes
    int getDistance(int,int); // accesseur
    CDistance& operator=(const CDistance &); // surchargeur
};

#endif
