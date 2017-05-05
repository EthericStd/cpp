#include<ctime>
#include<cstdlib>
#include<iostream>

#include"Croisement.h"

int* zeros(int N)
{
    int *t = new int[N];
    for(int i=0;i<N;i++)
    {
        t[i] = 0;
    }
    return t;
}

int* random(int* visited, int N)
{
    int* ran = new int[N];
    int r1, r2;
    r1 = rand() % N;
    while(visited[r1] == 1) r1 = rand() % N;
    r2 = rand() % N;
    while((visited[r2] == 1) || (r2 == r1)) r2 = rand() % N;
    ran[0] = r1;
    ran[1] = r2;
    return ran;
}

void croise(CPopulation< CChemin<CVille> >* Pop)
{
    int N = (*Pop)[0].get_lenght();
    int index = (rand() % (N-1)) + 1;
    CVille t1[N];
    CVille t2[N];
    // cout<<endl<<"index "<<index<<endl;
    // cout<<"N "<<N<<endl;
    for(int i=0;i<index;i++)
    {
        // cout<<"i "<<i<<endl;
        t1[i] = (*Pop)[0][i];
        t2[i] = (*Pop)[1][i];
    }
    for(int j=index;j<N;j++)
    {
        // cout<<"j "<<j<<endl;
        t1[j] = (*Pop)[1][j];
        t2[j] = (*Pop)[0][j];
    }
    CChemin<CVille> c1(t1, N);
    CChemin<CVille> c2(t2, N);
    CChemin<CVille> che_memo[2] = {c1, c2};
    // cout<<endl<<"chemins"<<endl;
    // c1.Print();
    // cout<<endl<<"chemins"<<endl;
    // c2.Print();
    CPopulation< CChemin<CVille> > Pop_memo(che_memo, 2);
    // cout<<endl<<"Avant re pop_memo"<<endl;
    // Pop_memo.Print();
    (*Pop) = Pop_memo;
}

CPopulation< CChemin<CVille> > Croisement::start(CPopulation< CChemin<CVille> >& Pop)
{

    int N = Pop.get_lenght();
    CChemin<CVille> tC[N];
    int* visited = zeros(N);
    int* ran;

    CPopulation< CChemin<CVille> > Pop1;

    for(int i=0; i<N/2;i++)
    {
        // cout<<"N "<<N/2<<"  i "<<i<<endl;
        // cout<<"visited "<<visited[0]<<" "<<visited[1]<<" "<<visited[2]<<" "<<visited[3]<<endl;

        ran = random(visited, N);
        cout<<"ran "<<ran[0]<<" "<<ran[1]<<endl;
        CChemin<CVille> che_memo[2] = {Pop[ran[0]],Pop[ran[1]]};
        CPopulation< CChemin<CVille> > Pop_memo(che_memo, 2);

        // cout<<endl<<"Pop_memo"<<endl;
        // Pop_memo.Print();
        croise(&Pop_memo);
        // cout<<endl<<"Pop_memo apres"<<endl;
        // Pop_memo.Print();

        Pop1 = Pop1 + Pop_memo;
        // cout<<endl<<"Pop1"<<endl;
        // Pop1.Print();

        visited[ran[0]] = 1;
        visited[ran[1]] = 1;
    }
    // cout<<"visited";
    // for(int r=0;r<N;r++)
    // {
    //     cout<<visited[r]<<" ";
    // }
    // cout<<endl;

    return Pop1;
}
