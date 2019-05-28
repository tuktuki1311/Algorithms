#include<bits/stdc++.h>

using namespace std;

#define SIZE 100

struct edge
{
    int u,v,w;

    bool operator<(const edge &p)const
    {
        return w < p.w;
    }
};

vector<edge>graph;
int par[SIZE];

void makeSet(int n)
{
    for(int i=0;i<n;i++)
        par[i]=i;
}

int findSet(int r)
{
    if(par[r]==r)
        return r;
    else
        return findSet(par[r]);
}

int kruskal(int n)
{
    makeSet(n);

    sort(graph.begin(),graph.end());

    int sum=0,cnt=0;
    for(int i=0;i<graph.size();i++)
    {
        int U=findSet(graph[i].u);
        int V=findSet(graph[i].v);

        if(U!=V)
        {
            par[U]=V;
            cnt++;
            sum+=graph[i].w;

            if(cnt==n-1)
                break;

            cout << U <<"-"<< V << endl;
        }
    }
    return sum;

}
int main()
{
    int node,edges;
    cout<<"Enter Nodes and Edges"<<endl;
    cin>>node>>edges;

    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edge data;
        data.u=u;
        data.v=v;
        data.w=w;

        graph.push_back(data);
    }
    cout<<kruskal(node)<<endl;
return 0;
}
