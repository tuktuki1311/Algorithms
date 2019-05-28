#include<bits/stdc++.h>
#define MAX 1025
using namespace std;

const int INF = 0x3f3f3f3f;
struct edge{
    int u,v,w;
};

int main()
{
  int dis[MAX]={INF};
  vector<edge>vec;

  int tc,n,e;
  cin>>tc;

  while(tc--){
    cin>>n>>e;
    vec.clear();
    memset(dis, 0x3f, sizeof dis);

    for(int i=0;i<e;i++){

     int u,v,w;
     edge node;
     cin>>u>>v>>w;
     node.u=u;
     node.v=v;
     node.w=w;

     vec.push_back(node);
    }
     for(int i=0;i<n-1;i++){
      for(int j=0;j<vec.size();j++){
            int ff=vec[j].v;
            int ss=vec[j].u;
            int c=vec[j].w;

            if(dis[ff]>dis[ss]+c)
                dis[ff]=dis[ss]+c;
        }

      }
      int f=0;

       for(int j=0;j<vec.size();j++){
            int ff=vec[j].v;
            int ss=vec[j].u;
            int c=vec[j].w;

            if(dis[ff]>dis[ss]+c){
                dis[ff]=dis[ss]+c;
                f=1;
                break;
            }
        }

        if(f)
            printf("possible\n");
        else
            printf("not possible\n");

    }
return 0;
}
