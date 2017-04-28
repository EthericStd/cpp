#ifndef ICHROMOSOME
#define ICHROMOSOME

template <class T> class IChromosome
{
    /*
    Classe représentant un Ichromosome
    composée de plusieurs génes
    */
private:
    int mN;
    T* mIChromosome;
public:
    IChromosome();
    IChromosome(T* , int);
    IChromosome(const IChromosome&);
    ~IChromosome();

    IChromosome& operator=(IChromosome&);

    int get_lenght();
    void Print();
};

#endif
