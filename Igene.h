#ifndef IGENE
#define IGENE

#include<string>

using namespace std;

template <class A> class Gene
{
    /*
    Classe représentant un gène
    */
private:
    string mName;
public:
    Gene();
    string get_name();
    void put_name(string);
};

#endif
