#ifndef __CVille__
#define __CVille__

#include<string>

using namespace std;

class CVille
{
private:
    string mName;
    int mX;
    int mY;
public:
    CVille();
    CVille(string, int, int);
    string get_name();
    int get_x();
    int get_y();
    void Print();
};

#endif
