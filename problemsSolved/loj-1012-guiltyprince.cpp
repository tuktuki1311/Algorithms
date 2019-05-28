#include<bits/stdc++.h>
#define MAX 200
#define pii pair <int,int>

using namespace std;

int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};

/*int dx[]={2,2,1,-1,-2,-2,-1,1};
int dy[]={1,-1,-2,-2,-1,1,2,2};*/

char graph[MAX][MAX];
bool visited[MAX][MAX];

int row,col;

int BFS(int pos1,int pos2)
{
    int i,j,x,y,cnt=0;

    visited[pos1][pos2]=true;
    queue<pii>q;
    q.push(pii(pos1,pos2));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

        for(int k=0; k<4; k++)
        {
            i=top.first+dx[k];
            j=top.second+dy[k];

            if(i>=0 && j>=0 && i<row && j<col)
            {
                if(!visited[i][j] && graph[i][j]=='.')
                {
                    visited[i][j]=true;
                    q.push(pii(i,j));
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main()
{
    int t,cn;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        memset (visited , 0 , sizeof (visited));
        cin >> col >> row;
        int pos1;
        int pos2;
        for(int j=0; j<row; j++)
        {
            for(int k=0; k<col; k++)
            {
                cin>>graph[j][k];
                if(graph[j][k]=='@')
                {
                    pos1=j;
                    pos2=k;
                }
            }
        }
        cn=BFS(pos1,pos2);
        printf("Case %d: %d\n",i+1,cn+1);

    }

    return 0;
}
