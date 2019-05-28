#include<bits/stdc++.h>
#define mx 200001
using namespace std;
int N;

vector<int>edge[mx],cost[mx];
const int infinity = 1000000000;
struct data
{
    int city,dist;
     bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source,int destination)
{

    int d[mx];
    for(int i=0;i<mx;i++)
        d[i]=infinity;
    priority_queue<data>q;
    data u,v;

    u.city=source;
    u.dist=0;
     q.push(u);
    d[source]=0;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        int ucost=d[u.city];
        for(int i=0;i<edge[u.city].size();i++)
        {
            v.city=edge[u.city][i];
            v.dist=ucost+cost[u.city][i];
            if(d[v.city]>v.dist)
            {
                d[v.city]=v.dist;
                q.push(v);
                cout << d[v.city] << endl;
            }
        }
    }
    return d[destination];
}

int main()
{
    int n,e,a,b,w;
    cin >> n >> e;
    for(int i=1;i<=e;i++)
    {
        cin >> a >> b >> w;
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }
    int source,dest;
    cin >> source >> dest;
    int ans = dijkstra(source,dest);
    cout << ans << endl;

}

