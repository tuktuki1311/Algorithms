#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 101111
typedef pair<int,int>pii;

vector<int>graph[MAXSIZE];



int bfs(int src,int ttl)
{
    queue<int>q;
    bool visit[MAXSIZE]= {false};
    int cost[MAXSIZE]= {0};
    vector<pii>pa;

    cost[src]=0;
    visit[src]=true;
    q.push(src);
    pa.push_back(pii(cost[src],src));

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];

            if(!visit[v])
            {
                visit[v]=true;
                cost[v]=cost[u]+1;
                pa.push_back(pii(cost[v],v));
                q.push(v);

            }
        }
    }
    sort(pa.begin(),pa.end());
    int cnt=0;

    for(int j=0; j<pa.size(); j++)
        {

        //cout << pa[j].first << ' ' << j <<' ' << pa[j].second << ' ' << endl;
        if(pa[j].first>ttl)
            break;
        cnt++;
        }
   // cout << cnt << endl;
    return cnt;


}
int main()
{
    int tc,cases=1;

    while((cin>>tc)&&tc)
    {
        map<int,bool>mp;
        int node=0;

        for(int i=0; i<tc; i++)
        {
            int u,v;
            cin>>u>>v;

            graph[u].push_back(v);
            graph[v].push_back(u);

            if(mp[u]==0)
            {
               // cout << mp[u] <<  ' ' << u << endl;
                mp[u]=1;
                node++;
            }

            if(mp[v]==0)
            {
                mp[v]=1;
                node++;
            }
        }

        int src,ttl;

        while(cin>>src>>ttl)
        {
            if(src==0 && ttl==0)
                break;

            if(ttl==0)
               // cout<<"Case " << cases++ << ": " << node-1 << " nodes not reachable from node " << src << " with TTL = " << ttl<<endl;
 printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,node-1,src,ttl);
            else
            {
                int no=bfs(src,ttl);
                //cout<<"Case " << cases++ << ": " << node-no << " nodes not reachable from node " << src << " with TTL = " << ttl<<endl;
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,node-no,src,ttl);
            }

        }
        for(int i=0; i<=MAXSIZE; i++)
            graph[i].clear();

    }
}
