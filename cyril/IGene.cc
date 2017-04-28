#include<iostream>
#include"IGene.h"

using namespace std;

IGene::IGene()
{
    mName = "";
}

string IGene::get_name()
{
    return mName;
}

void IGene::Print()
{
    cout<<mName<<endl;
}
