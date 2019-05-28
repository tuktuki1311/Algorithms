#include <bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool vis[100][100];
int cost[100][100];
queue< pii > q;
int m,p;
string str[100];


int bfs(int a,int b,int c,int d)
{
    int x1,y1;
      memset(vis,0,sizeof(vis));
      memset(cost,0,sizeof(cost));
      while(!q.empty()) q.pop();

      vis[a][b]=true;
      cost[a][b]=0;
      q.push(pii(a,b));

      while(!q.empty())
      {
          pii u=q.front();
          q.pop();
          int x=u.first;
          int y=u.second;

          for(int i=0;i<4;i++)
          {
              x1=x+dx[i];
              y1=y+dy[i];

              if(x1>=0 && y1>=0 && x1<m && y1<p && !vis[x1][y1] && (str[x1][y1]!='m' && str[x1][y1]!='#'))

              {
                  vis[x1][y1]=true;
                  cost[x1][y1]= cost[x][y]+1;
                  q.push(pii(x1,y1));
              }

          }
          if(x==c && y==d){
                cout << cost[c][d] << endl;
            return cost[c][d];
          }

      }

}

int main()
{
  int n,a1,a2,b1,b2,c1,c2,h1,h2,res[10],res2,res3,f=1;

  cin >> n;

  while(n--)
  {
    cin >> m >> p;

    for(int i=0;i<m;i++)
      cin >> str[i];

      for(int i=0;i<m;i++)
       for(int j=0;j<p;j++)
       {
         if(str[i][j]=='h')
         {
            h1=i;
            h2=j;
            cout << h1 << ' ' << h2 << endl;
            break;
         }
       }

      int c=0;
      for(int i=0;i<m;i++)
      {
       for(int j=0;j<p;j++)
       {
         if(str[i][j]=='a')
         {
           res[0]=bfs(i,j,h1,h2);
           cout << i << ' ' << j << endl;
           c++;
         }
         else if(str[i][j]=='b')
         {
           res[1]=bfs(i,j,h1,h2);
           cout << i << ' ' << j << endl;
           c++;
         }
         else if(str[i][j]=='c')
         {
           res[2]=bfs(i,j,h1,h2);
           cout << i << ' ' << j << endl;
           c++;
         }

       }
       if(c==3)
       break;
     }
    sort(res,res+3);

     cout << "Case " << f++ << ": " << res[2] << endl;

  }
}
