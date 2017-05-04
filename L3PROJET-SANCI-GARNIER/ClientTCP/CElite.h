#ifndef ____CELITE____
#define ____CELITE____

#include "CChromosome.h"
#include "CPossiblePath.h"
#include "CDistance.h"

class CElite{
    private:
    
        int * m_ChromosomeElite;
        int m_length;
        
    public:
    
        // constructeur
        
        CElite(int,CPossiblePath &,CDistance &);
        
        // destructeur
        
        ~CElite();
        
        // methode
        
        int fitness(CChromosome &,CDistance &); // calcul du meilleur
        void mute(CPossiblePath &,CDistance &); // mutation
        void injection(CPossiblePath &); // injection des meilleur élites dans une nouvelle pop
        void crossing(CPossiblePath &,CDistance &); // croisement
        int getPathElite(int); // accesseur
        int getLength(); // accesseur
};

#endif
