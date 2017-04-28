#ifndef IGENE
#define IGENE

#include<string>

using namespace std;

class IGene
{
    /*
    Classe représentant un gène
    */
private:
    string mName;
public:
    IGene();
    IGene(string);
    string get_name();
    void Print();
};

#endif
