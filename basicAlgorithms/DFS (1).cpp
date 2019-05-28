#include<bits/stdc++.h>

using namespace std;
#define white 0
#define gray 1
#define black 2
#define green 4
#define maxsize 10
int grid[maxsize][maxsize];
int clr[maxsize];
int per[maxsize];
int discvr[maxsize];
int finish[maxsize];
int v,e;
int t,c,p;
void dfs_visit(int grid[maxsize][maxsize],int u)
{

    clr[u]=gray;
    discvr[u]=++t;
    for(int i=0;i<v;i++)
    {

        if(grid[u][i]!=0)
        {
             if(clr[i]==black)
                p++;
            if(clr[i]==white)
            {
                per[i]=u;
                clr[i]=gray;
                dfs_visit(grid,i);
            }

        }
    }
    clr[u]=black;
   // printf("%d ",u);
    finish[u]=++t;

}
void dfs(int grid[maxsize][maxsize])
{
    for(int i=0;i<v;i++)
    {
        per[i]=-1;
        clr[i]=white;
    }

    for(int i=0;i<v;i++)
    {
        if(clr[i]==white)
        {

            dfs_visit(grid,i);
           // cout << endl;
              c++;
        }
    }
}
int main()
{

    int x,y;
    freopen("input.txt","r",stdin);
   scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&x,&y);

        grid[x][y]=1;
        grid[y][x]=1;
    }
    dfs(grid);
   // cout << "component " << c << endl;
    cout << p << endl;
}
