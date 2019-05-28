#include<bits/stdc++.h>
using namespace std;

#define MAX 999999
int par[MAX],element[MAX],rankArray[MAX];
int maximum=1;

void makeSet(int n)
{
    for(int i=1; i<=n; i++)
    {
        par[i]=i;
        element[i]=1;
        rankArray[i]=0;
    }
}

int findSet(int r)
{
    if(par[r]==r)
        return r;
    else
        return par[r]=findSet(par[r]);
}

void Union(int x,int y)
{
    int X=findSet(x);
    int Y=findSet(y);

    if(X==Y)
        return;
    else
    {
        if(rankArray[X]>rankArray[Y])
        {
            par[Y]=X;
            element[X]+=element[Y];
            maximum=max(maximum,element[X]);
           // maximum=max(maximum,element[x]);
        }

        else
        {
            par[X]=Y;
            element[Y]+=element[X];
           // maximum=max(maximum,element[y]);
            maximum=max(maximum,element[Y]);
            if(rankArray[X]==rankArray[Y])
                rankArray[Y]=rankArray[Y]+1;

        }
    }
}
    int main()
    {
        int tc,numberCitizen,numberPair;
        cin>>tc;

        while(tc--)
        {
            cin>>numberCitizen>>numberPair;
            makeSet(numberCitizen);

            while(numberPair--)
            {
                int x,y;
                cin>>x>>y;
                Union(x,y);
            }
            cout << maximum << endl;
            maximum=1;
        }
        return 0;
    }
