#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>pii;
const int SIZE = 1024;
const int INF = 0x3f3f3f3f;

vector<pii>graph[SIZE];
int dis[SIZE];
int par[SIZE];
bool visit[SIZE];

void prims(int src,int n)
{
    priority_queue<pii,vector<pii>,greater<pii> >Q;

   for(int i=1;i<=n;i++)
        dis[i]=INF;

    dis[src]=0;
    par[src]=0;
    Q.push(make_pair(0,src));

    while(!Q.empty())
    {
        int u=Q.top().second;
        int c=Q.top().first;
        Q.pop();
        visit[u]=true;

        for(int i=0; i<graph[u].size();i++)
        {
            int v=graph[u][i].first;
            int w=graph[u][i].second;

            if(dis[v]>w && !visit[v])
            {
                dis[v]=w;
                par[v]=u;
                Q.push(make_pair(dis[v],v));
            }
        }
    }

}
int main()
{
    int node,edge,src,sum=0;

    cout<<"Enter nodes and edges"<<endl;
    cin>>node>>edge;

    for(int i=1; i<=edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(pii(v,w));
        graph[v].push_back(pii(u,w));
    }
    cout<<"Enter Source" << endl;
    cin>>src;

    prims(src,node);

    for(int i=1;i<=edge;i++)
        sum+=dis[i];
    cout<<sum<<endl;
return 0;
}
