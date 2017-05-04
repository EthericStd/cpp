#ifndef CVille
#define CVille

#include<string>

using namespace std;

class CVille
{
    /*
    Classe représentant une ville
    */
private:
    string mName;
    int x;
    int y;
public:
    CVille();
    CVille(string);
    string get_name();
    void Print();
};

#endif
