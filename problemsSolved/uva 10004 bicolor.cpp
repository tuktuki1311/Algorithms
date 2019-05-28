#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100000
#define white 0
#define black 1
#define grey 2
#define inf 999999

vector<int>adj[MAX];
int color[MAX];

void clearVector(int n)
{
    for(int i=0; i<=n; i++)
        adj[i].clear();
    for(int i=0; i<=n; i++)
        color[i]=white;
}
bool bfs(int s,int n)//s is the starting vertex && n is the number of vertexes
{
    int flag=0;

    for(int j=0; j<n; j++)
    {
        color[j]=white;
    }

    queue<int>Q;
    color[s]=grey;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            if(color[adj[u][i]]==white)
            {
                if(color[u]==grey)
                    color[adj[u][i]]=black;
                else
                    color[adj[u][i]]=grey;

                    int v=adj[u][i];
                    Q.push(v);
            }

            else
            {
                if(color[adj[u][i]]==color[u])
                {
                    flag=1;
                    break;
                }
            }
           // cout << color[adj[u][i]] << endl;
        }
        if(flag)
            break;
    }
    if(flag)
        return false;
    else
        return true;
}
int main ()
{
    //memset(matrix,0,sizeof(matrix));
    int edge,node,n1,n2,c;
    // freopen("inputBfsAlgo.txt","r",stdin);
    while((cin>>node)&&node)
    {
        cin>>edge;

        for(int i=0; i<edge; i++)
        {
            cin>>n1>>n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        bool res=bfs(0,node);
        if(res)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;
        clearVector(edge);

    }
}

