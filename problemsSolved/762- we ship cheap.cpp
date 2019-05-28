#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 100003

vector<int>graph[MAXSIZE];
map<int,string>citi;
int path[MAXSIZE];
bool visit[MAXSIZE];
vector<string>par;

void printPath(int des,int src)
{
    int u=path[des];

    if(u!=src)
        printPath(u,src);
        par.push_back(citi[u]);
}
void bfs(int src, int des)
{
    queue<int>q;

    visit[src]=true;
   // path[src]=src;
    q.push(src);


    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        int sz=graph[u].size();

        for(int i=0; i<sz; i++)
        {
            int v=graph[u][i];
            if(!visit[v])
            {
                visit[v]=true;
                path[v]=u;
                q.push(v);

            }
        }
    }

   if(path[des]==-1)
    {
        cout << "No route" << endl;
        return;
    }
    else
    {
        printPath(des,src);
        par.push_back(citi[des]);

    }

    for(int k=0; k<par.size()-1;k++)
    {
        cout << par[k] << ' ' << par[k+1] << endl;
    }
}
int main()
{
    int edges,f=0;

    while(scanf("%d",&edges)!=EOF)
    {
        map<string,int>city;
        int index=1;
        for(int i=1; i<=edges; i++)
        {
            string start,endd;
            cin>>start>>endd;

            if(!city[start])
            {
                //cout << index << endl;
                city[start]=index;
                citi[index]=start;
                index++;
                //cout << index << endl;

            }
            if(!city[endd])
            {
               // cout << index << endl;
                city[endd]=index;
                citi[index]=endd;
                index++;
               // cout << index << endl;

            }

            //index++;
            graph[city[start]].push_back(city[endd]);
            graph[city[endd]].push_back(city[start]);

        }

        memset(visit,false,sizeof visit);
        memset(path,-1,sizeof path);

        string src,des;
        cin>>src>>des;

        if(f)
            puts("");
        bfs(city[src],city[des]);

        for(int i=0; i<=edges; i++)
            graph[i].clear();
            par.clear();
            city.clear();
            citi.clear();

        f=1;

    }
}
