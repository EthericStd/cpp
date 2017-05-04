#ifndef CChemin
#define CChemin

#include"CVille.h"

template <class T> class CChemin
{
    /*
    Classe représentant un CChemin
    composée de plusieurs génes
    */
private:
    int mN;
    T* mCChemin;
public:
    CChemin();
    CChemin(T* , int);
    CChemin(const CChemin&);
    ~CChemin();

    CChemin& operator=(CChemin&);

    int get_lenght();
    void Print();

    CVille& operator[](int);
};

#endif
