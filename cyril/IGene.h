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
    string get_name();
    void Print();
};

#endif
