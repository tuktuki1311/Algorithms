#include<bits/stdc++.h>

using namespace std;
#define SIZE 105

vector<int>graph[SIZE];
vector<int>cost[SIZE];
bool visit[SIZE];
int par[SIZE];
double x[SIZE],y[SIZE];
int ranking[SIZE];


struct edge
{
    int v,u;
    double w;

    bool operator<(edge p)const
    {
    return w > p.w;
    }
};

int findSet(int r)
{
    if(par[r]==r)
        return r;
    else
        return findSet(par[r]);
}

void Union(int a,int b){

    if(ranking[a]<ranking[b])
        par[a]=findSet(b);
    else{
        par[b]=findSet(a);
        if(ranking[a]==ranking[b])
            ranking[a]++;
    }

}

double prims(int n)
{
     int cnt=0;
     edge node;
     priority_queue<edge>pq;
     double costing,total_costing;

     for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            costing=sqrt(((x[j]-x[i])*(x[j]-x[i]))+((y[j]-y[i])*(y[j]-y[i])));
            node.u=i;
            node.v=j;
            node.w=costing;

            pq.push(node);
        }

    while(!pq.empty()){
      if(cnt==n-1)
        break;

       int A=pq.top().u;
       int B=pq.top().v;
       double Cost=pq.top().w;
       int PA=findSet(A);
       int PB=findSet(B);
       if(PA!=PB){
            total_costing+=Cost;
            cnt++;
            Union(PA,PB);
        }
        pq.pop();

    }
  return total_costing;
}
int main()
{
    int tc,n;

    cin>>tc;

    while(tc--){
      cin>>n;

      for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            par[i]=i;
            ranking[i]=0;

      }
    printf("%.2lf\n",prims(n));
    if(tc)
    cout<<endl;
    }


return 0;
}
