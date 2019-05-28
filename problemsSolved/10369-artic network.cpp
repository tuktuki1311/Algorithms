#include<bits/stdc++.h>

using namespace std;

#define SIZE 103
#define inf 1<<29

struct edge
{
    int u,v,w;

    /*bool operator<(edge p)const
    {
    return w > p.w;
    }*/
};

int comp(edge a,edge b)
{
    return a.w<b.w;
}

vector<edge>graph;
int par[SIZE],ed[SIZE];
int sz;

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
        return (par[r]=findSet(par[r]));
}

int kruskal(int n)
{
    makeSet(n);
    sort(graph.begin(),graph.end(),comp);

    int sum=0;
    int cnt=0;
    int ans=-1;

    for(int i=0;i<graph.size() && cnt<n-1;i++)
    {
        int U=findSet(graph[i].u);
        int V=findSet(graph[i].v);

        if(U!=V)
        {
            if(U>V)
              par[U]=V;
            else par[V]=U;
            //par[U]=V;
            cnt++;
            sum+=graph[i].w;
            ed[sz++]=i;
            //cout << sum << endl;

           /* if(cnt==n-1)
                break;*/

            //cout << U <<"-"<< V << endl;
        }
    }
    if(cnt==n-1)
        ans=sum;

    return ans;


}
int main()
{
   int tc,n,e,ans=0;;
   double c;
   edge node;

   scanf("%d",&tc);

   for(int t=1;t<=tc;t++){

     scanf("%d%d",&n,&e);

     graph.clear();
     memset(ed,0,sizeof ed);

     for(int i=0; i<e; i++){
        int u,v,w;

        scanf("%d%d%d",&u,&v,&w);
        node.u=u;
        node.v=v;
        node.w=w;

        graph.push_back(node);

     }

    ans=kruskal(n);
    printf("Case #%d : ",t);
    //cout << "First " << ans << endl;
    if(ans==-1)
    printf("No way\n");

    else{

        int minii=inf;
        for(int i=0; i<sz; i++){
            makeSet(n);
            int ans=0;
            int cnt=0;

            for(int j=0;j<e && cnt<n-1;j++){
              if(ed[i]!=j){
                 int U=findSet(graph[j].u);
                 int V=findSet(graph[j].v);
                   if(U!=V){
                     //par[U]=V;
                     if(U>V)
                        par[U]=V;
                     else par[V]=U;
                     cnt++;
                     ans+=graph[j].w;

                     //cout << ans << endl;
                    /*if(cnt==n-1)
                      break;*/
                   }
                }
            }

            if(cnt==n-1 && minii>ans)
                minii=ans;
         }
         if(minii==inf || minii==0)
            printf("No second way\n");
         else
            printf("%d\n",minii);
      }

   }

return 0;
}

