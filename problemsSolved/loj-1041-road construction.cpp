#include<bits/stdc++.h>
using namespace std;

int par[155];
//int n;

struct edge
{
    int u,v,w;

    bool operator<(const edge &p) const
    {
        return w<p.w;
    }
};

vector<edge>graph;

void makeSet(int n)
{
    for(int i=0; i<=n; i++)
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
    //cout << n << endl;

    makeSet(n);
    sort(graph.begin(),graph.end());

    //cout << n << endl;

    int cnt=0,sum=0,f=0;
    for(int i=0; i<(int)graph.size(); i++)
    {
        int U=findSet(graph[i].u);
        int V=findSet(graph[i].v);

        if(U!=V)
        {
            par[U]=V;
            sum+=graph[i].w;
            cnt++;
            if(cnt==n-1)
            {
                f=1;
                break;
            }
        }
    }

    if(f)
        return sum;
    else
        return -1;

}
int main()
{
    int tc;
    cin>>tc;

    for(int i=1; i<=tc; i++)
    {
        int edges;
        cin>>edges;

        map<string,int>city;
        //map<int,string>citi;

        int index=1;

        for(int k=1; k<=edges; k++)
        {
            string start,endd;
            edge data;
            int weight;

            cin>>start>>endd>>weight;

            if(!city[start])
            {
                city[start]=index;
              // citi[index]=start;
                index++;
            }
            if(!city[endd])
            {
                city[endd]=index;
              // citi[index]=endd;
                index++;
            }

           /* if(city.find(start)==city.end())
                city[start]=index++;
            if(city.find(endd)==city.end())
                city[endd]=index++;*/

            data.u=city[start];
            data.v=city[endd];
            data.w=weight;

            graph.push_back(data);

        }
        int n=index-1;
      /*  cout << n << endl;

        for(int f=0; f<graph.size();f++){
                string x= citi[graph[f].u];
                string y = citi[graph[f].v];
            cout << graph[f].u << ' ' << graph[f].v << ' ' << graph[f].w << endl;
       }*/
        int res=kruskal(n);

        if(res!=-1)
            printf("Case %d: %d\n",i,res);
        else
            printf("Case %d: Impossible\n",i);
            graph.clear();

    }
    return 0;
}
