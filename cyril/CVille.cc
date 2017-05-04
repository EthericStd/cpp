#include<iostream>
#include"CVille.h"

using namespace std;

CVille::CVille()
{
    mName = "";
}

CVille::CVille(string pName)
{
    mName = pName;
}


string CVille::get_name()
{
    return mName;
}

void CVille::Print()
{
    cout<<mName<<endl;
}
