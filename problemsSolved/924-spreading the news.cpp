#include<bits/stdc++.h>

#define maxsize 2555

using namespace std;

vector<int>graph[maxsize];
bool visit[maxsize];
int height[maxsize];
int width[maxsize];

void cleararr()
{
    memset(visit,0,sizeof(visit));
    memset(height,0,sizeof(height));
    memset(width,0,sizeof(width));
}
void bfs(int s,int nodes)
{
    visit[s]=true;
    height[s]=0;
    width[s]=0;

    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];

            if(!visit[v])
            {
               visit[v]=true;
               height[v]=height[u]+1;
               width[height[v]]++;
               q.push(v);
            }
        }
    }

    int maxi=-1,index;

    for(int i=0;i<nodes;i++)
    {
        if(width[i]>maxi)
        {
            maxi=width[i];
            index=i;

        }
    }

    if(maxi>0)
        cout << maxi <<' ' <<index << endl;
    else
        cout <<0<< endl;

}

int main()
{
    int nodes,edge,n1,test,source;
    cin>>nodes;

    for(int i=0;i<nodes;i++)
    {
        cin>>edge;

        for(int j=0;j<edge;j++)
        {
            cin>>n1;
            graph[i].push_back(n1);

        }
    }

    cin>>test;
    while(test--)
    {
        cin>>source;
        bfs(source,nodes);
        cleararr();

    }



return 0;
}
