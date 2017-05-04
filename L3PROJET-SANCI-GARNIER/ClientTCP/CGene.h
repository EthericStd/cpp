#ifndef ___GENE___
#define ___GENE___

class CGene
{
    private:

        int m_Num;
        int m_Coordx;
        int m_Coordy;

    public:

        // Constructeurs
        
        CGene();
        CGene(int);
        
        // destructeur
        
        ~CGene();

        // Methodes

        int getNum(); // accesseur
        int getCoordx(); // accesseur
        int getCoordy(); // accesseur
        void print(); // afficheur
};

#endif
