#ifndef __CVille__
#define __CVille__

#include<string>

using namespace std;

class CVille
{
private:
    // nom de la ville
    string mName;
    // coordonnée x de la ville
    int mX;
    // coordonnée y de la ville
    int mY;
public:
    // constructeurs
    CVille();
    CVille(string, int, int);

    // retourne le nom de la ville
    string get_name();
    // retourne les coordonnées de la ville
    int get_x();
    int get_y();
    // affiche la ville sur le terminal
    void Print();
};

#endif
