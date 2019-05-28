#include<bits/stdc++.h>
#define MAX 1010
#define pii pair <int,int>

using namespace std;

int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};

/*int dx[]={2,2,1,-1,-2,-2,-1,1};
int dy[]={1,-1,-2,-2,-1,1,2,2};*/
int graph[MAX][MAX];
bool visited[MAX][MAX];
int cost[MAX][MAX];

int row,col,posx,posy,desx,desy;

void reset()
{
    memset(visited,0,sizeof(visited));
    memset(cost,0,sizeof(cost));
    memset(graph,0,sizeof(graph));
}

void BFS()
{
    int i,j;

    visited[posx][posy]=true;
    cost[posx][posy]=0;
    queue<pii>q;

    q.push(pii(posx,posy));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

        for(int k=0; k<4; k++)
        {
            i=top.first+dx[k];
            j=top.second+dy[k];

            if(i>=0 && j>=0 && i<row && j<col && !visited[i][j] && graph[i][j]==0)
            {
                cost[i][j]=cost[top.first][top.second]+1;
                visited[i][j]=true;
               // graph[i][j]=1;
                q.push(pii(i,j));
            }
        }
    }
}

int main()
{
    int edeges,bombx,bomby,bomb;

    while(cin>>row>>col)
    {
        if(row==0 && col==0)
            break;
        reset();

        cin >> edeges;

        for(int i=0; i<edeges; i++)
        {
            cin>>bombx>>bomb;

            while(bomb--)
            {
                cin>>bomby;
                graph[bombx][bomby]=1;
            }
        }
        cin >> posx >> posy >> desx >> desy;
        BFS();
        cout << cost[desx][desy] << endl;

    }
    return 0;
}
