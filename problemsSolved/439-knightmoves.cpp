#include<bits/stdc++.h>
#define MAX 1010
#define pii pair <int,int>

using namespace std;

/*int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};*/

int dx[]={2,2,1,-1,-2,-2,-1,1};
int dy[]={1,-1,-2,-2,-1,1,2,2};

int graph[MAX][MAX];
bool visited[MAX][MAX];
int cost[MAX][MAX];

int row,col,posx,posy,desx,desy;

void reset()
{
    memset(visited,0,sizeof(visited));
    memset(cost,0,sizeof(cost));
   // memset(graph,0,sizeof(graph));
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

        for(int k=0; k<8; k++)
        {
            i=top.first+dx[k];
            j=top.second+dy[k];

            if(i>=0 && j>=0 && i<8 && j<8 && !visited[i][j])
            {
                visited[i][j]=true;
                cost[i][j]=cost[top.first][top.second]+1;
                q.push(pii(i,j));
            }
        }
    }
}

int main()
{
    string start,finish;

    while(cin>>start>>finish)
    {
        posx=int(start[0]-'a');
        posy=start[1]-'0';
        posy--;

        desx=int(finish[0]-'a');
        desy=finish[1]-'0';
        desy--;

        reset();
        BFS();
       // reset();
       // printf("To get from xx to yy takes n knight moves.");
        cout << "To get from " <<start << " to " << finish << " takes " << cost[desx][desy] << " knight moves." << endl;
    }
return 0;
}
