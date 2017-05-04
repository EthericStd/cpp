#ifndef ____CGENELIST____
#define ____CGENELIST____

#include "CGene.h"

class CGeneList{
    private:
    
        CGene *m_List;
        int m_NbGene;
    
    public:
    
        // Constructeur
        
        CGeneList();
        CGeneList(const int);
        CGeneList(const CGeneList&); // constructeur par recopie
        
        // Destructeur
        
        ~CGeneList();
        
        // Methodes
        
        void print(); // afficheur
        int getNbGene(); // accesseur
        CGene * getList(); // accesseur
        CGene getGene(int); // accesseur
        CGeneList& operator=(const CGeneList&); // surchargeur
};
#endif
