#include<bits/stdc++.h>

using namespace std;
#define SIZE 100

vector<int>graph[SIZE];
vector<int>cost[SIZE];
bool visit[SIZE];
int par[SIZE];

struct edge
{
    int v,w;

    bool operator<(edge p)const
    {
    return w > p.w;
    }
};

void printpath(int source,int des)
{
    if(source==des)
    {
        cout << source << " ";
        return;
    }
    {
        printpath(source,par[des]);
        cout << des << " ";
    }
}

int prims(int src, int n)
{
    memset(visit,0,sizeof(visit));
    priority_queue<edge>pq;
    int sum=0,weight=0,v,u;
    for(int i=0; i<n-1; i++)
    {
         u=src;
        visit[src]=true;
       // cout<< u <<'-';
        for(int j=0; j<graph[u].size();j++)
        {
             v=graph[u][j];

            if(!visit[v])
            {
                edge data;
                data.v=v;
                data.w=cost[u][j];
                pq.push(data);
                par[v]=u;
               // cout << v << endl;
                // cout << u << " - "<< v <<endl;
            }

        }
       // if(!visit[v])
            cout << u << " - "<< v <<endl;
        while(visit[src])
        {
            edge t=pq.top();
            pq.pop();
            src=t.v;
            weight=t.w;
        }
        sum+=weight;
    }
    return sum;
}

int main()
{
    int node,edges;
    cin>>node>>edges;

    for(int i=1;i<=edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
         graph[v].push_back(u);
          cost[u].push_back(w);
           cost[v].push_back(w);
    }
    cout<<prims(1,node);
   // printPath(1,node);

return 0;
}
