#include<bits/stdc++.h>
using namespace std;
#define MAX 999999
int par[MAX];
set < int > s;
set < int > st;

int Find(int r)
{
    if(par[r]==r)
        return r;
    else
        return par[r]=Find(par[r]);
}

void Union(int a,int b)
{
    if(Find(a)!=Find(b))
        par[Find(a)]=par[b];
}


void makeset(int r)
{
    par[r]=r;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            makeset(i);
        int a, b;
        while(m--)
        {
            cin >> a >> b;
            Union(a,b);
        }
        for(int i=1; i<=n; i++)
        {
            st.insert(Find(i));
        }

        for(set <int>:: iterator it=st.begin(); it!=st.end(); it++)
        {
            int c=0;
            for(int j=1; j<=n; j++)
            {
                if(par[*it]==par[j])
                    c++;
            }
            s.insert(c);
        }
        /*  for(int i=1;i<=n;i++)
          {
              int c=0;
                for(int j=1;j<=n;j++)
               {
                   if(par[i]==par[j])
                      c++;
               }
               s.insert(c);
          }*/
        set <int> :: reverse_iterator it=s.rbegin();
        cout << *it << endl;
        s.clear();
    }
}
