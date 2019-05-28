#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100000
#define white 0
#define black 1
#define gray 2
#define inf 999999
vector<int>adj[MAX];
int color[MAX];
int dis[MAX];
int par[MAX];
void print_path(int s,int v)
{
    if(s==v)
        cout<<s<<" ";
    else if(par[v]==0)
    {
        cout<<"No Path Exist"<<endl;
    }
    else
    {
        print_path(s,par[v]);
        cout<<v<<" ";
    }
}
void bfs(int s,int n)//s is the starting vertex && n is the number of vertexes
{
    for(int u=0;u<n;u++)
    {
        color[u]=white;
        dis[u]=inf;
        par[u]=-1;
    }
    color[s]=gray;
    dis[s]=0;
    par[s]=-1;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(color[adj[u][i]]==white)
            {
                int v = adj[u][i];
                color[v]=gray;
                dis[v]=dis[u]+1;
                par[v]=u;
                Q.push(v);
            }
        }
        color[u]=black;
        //printf("%d ",u);
    }
}
int main ()
{
    //memset(matrix,0,sizeof(matrix));
    int edge,node,n1,n2,c;
   // freopen("inputBfsAlgo.txt","r",stdin);
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
   // cin>>c>>n1;
    bfs(3,node);
    cout<<"Shortest distance of 7: ";
    cout<<dis[7]<<endl;
    cout<<endl;
    cout<<"Shortest path 3 to 7: ";
    print_path(3,7);
    cout<<endl;
}

