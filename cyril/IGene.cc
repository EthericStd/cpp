#include<iostream>
#include"IGene.h"

using namespace std;

IGene::IGene()
{
    mName = "";
}

IGene::IGene(string pName)
{
    mName = pName;
}


string IGene::get_name()
{
    return mName;
}

void IGene::Print()
{
    cout<<mName<<endl;
}
