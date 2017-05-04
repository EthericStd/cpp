#include<iostream>
#include"CVille.h"

using namespace std;

CVille::CVille()
{
    mName = "";
    mX = 0;
    mY = 0;
}

CVille::CVille(string pName, int pX, int pY)
{
    mName = pName;
    mX = pX;
    mY = pY;
}

string CVille::get_name()
{
    return mName;
}

int CVille::get_x()
{
    return mX;
}

int CVille::get_y()
{
    return mY;
}

void CVille::Print()
{
    cout<<"Ville:"<<mName;
    cout<<" x:"<<mX;
    cout<<" y:"<<mY<<endl;
}
