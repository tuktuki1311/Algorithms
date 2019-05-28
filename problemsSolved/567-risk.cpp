#include<bits/stdc++.h>

#define nil -1
#define inf -99999
#define MAX 25

using namespace std;

vector<int>adj[MAX];
int par[MAX];


void bfs(int s, int d)
{
     bool visited[50]={false};
     int dis[50]={inf};

    visited[s]=true;
    dis[s]=0;
    //par[s]=nil;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u==d)
            break;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

           if(visited[v]==false)
            {
                visited[v]=true;
                dis[v]=dis[u]+1;
                //par[v]=u;
                Q.push(v);
            }
        }
       // Q.pop();
    }
   // cout << s <<' ' << "to" <<' ' << d << ":" << ' ' << dis[d] << endl;
     printf("%2d to %2d: %d\n",s,d,dis[d]);
}
int main()
{
    int nodeNo,edge,query,src,dest,n=1,x,y;
    while(scanf("%d",&edge)==1)
    {
        for(int j=1; j<=edge; j++)
        {
            cin>>nodeNo;
            adj[1].push_back(nodeNo);
            adj[nodeNo].push_back(1);

        }
        for(int i=2; i<=20; i++)
        {
            if(i<=19)
            {
                cin>>edge;

                while (edge--)
                {
                    cin>>nodeNo;
                    adj[i].push_back(nodeNo);
                    adj[nodeNo].push_back(i);
                }
            }
            else
            {

                cin>>query;
                //cout << "Test Set  #"<<n++ << endl;
                 printf("Test Set #%d\n",n++);
                //  print_path();
                while (query--)
                {
                    cin>>src>>dest;
                    bfs(src,dest);
                }

            }

        }
         printf("\n");
    for(int i=0; i<=25; i++)
        adj[i].clear();

    }
    return 0;
}
