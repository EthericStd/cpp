#ifndef ____CPOSSIBLEPATH____
#define ____CPOSSIBLEPATH____

#include "CChromosome.h"

class CPossiblePath{
    private:
    
        CChromosome * m_ListPath;
        int m_NbPath;

    public:
    
        // constructeur
        
        CPossiblePath(int);
        CPossiblePath(int,int); // nombre de listes et nombre de villes par listes
        CPossiblePath(const CPossiblePath &); // constructeur par recopie

        // destructeur
        
        ~CPossiblePath();
        
        // methodes
        
        void print(); // afficheur
        int getNbPath(); // accesseur
        CChromosome& getList(int);
        CPossiblePath& operator=(const CPossiblePath &); // surchargeur
        void setPathList(int,int,int); // mutateur
        void setNewPath(int); // mutateur
};

#endif
