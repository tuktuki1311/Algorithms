#include<bits/stdc++.h>
#define MAX 200
#define pii pair <int,int>

using namespace std;

int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};

/*int dx[]={2,2,1,-1,-2,-2,-1,1};
int dy[]={1,-1,-2,-2,-1,1,2,2};*/

// int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

char graph[MAX][MAX];
bool visited[MAX][MAX];
int cost[MAX][MAX];

int row,col;


void reset()
{
    memset(visited,0,sizeof(visited));
    memset(cost,0,sizeof(cost));
}
void BFS(int desx,int desy)
{
    int i,j,x,y;
    //reset();

    cost[desx][desy]=0;
    visited[desx][desy]=true;
    queue<pii>q;
    q.push(pii(desx,desy));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        x=top.first;
        y=top.second;

        for(int k=0; k<4; k++)
        {
            i=x+dx[k];
            j=y+dy[k];

            if(i>=0 && j>=0 && i<row && j<col && !visited[i][j] && (graph[i][j]!='m' || graph[i][j]!='#'))
            {

                visited[i][j]=true;
                q.push(pii(i,j));
                cost[i][j]=cost[x][y]+1;
                //q.push(pii(i,j));
            }
        }
    }
}



int main()
{
    int tc,posx1,posy1,posx2,posy2,posx3,posy3,desx,desy,cnt=0;
    int csm1,csm2,csm3,maxi;
    cin>> tc;

    for(int i=0; i<tc; i++)
    {
        cin >> row >> col;
        cnt=0;
        reset();

        for(int j=0; j<row;j++)
            for(int k=0;k<col;k++)
                cin >> graph[j][k];
        // reset();
        for(int j=0; j<row; j++)
        {
            for(int k=0; k<col; k++)
            {

                if(graph[j][k]=='a')
                {
                    posx1=j;
                    posy1=k;
                    //cout << posx1 << ' ' << posy1 << endl;
                }
                else if(graph[j][k]=='b')
                {
                    posx2=j;
                    posy2=k;
                    //cout << posx2 << ' ' << posy2 << endl;
                }

                else if(graph[j][k]=='c')
                {
                    posx3=j;
                    posy3=k;
                    //cout << posx3 << ' ' << posy3 << endl;
                }

                else if(graph[j][k]=='h')
                {
                    desx=j;
                    desy=k;
                    //cout << desx << ' ' << desy << endl;
                }
                else if(graph[j][k]=='m' || graph[j][k]=='#')
                    visited[j][k]=true;

            }
        }
        BFS(desx,desy);

        csm1=cost[posx1][posy1];
        csm2=cost[posx2][posy2];
        csm3=cost[posx3][posy3];

        maxi=max(csm1,max(csm2,csm3));
        //cout << csm1 << ' ' << csm2 << ' ' << csm3 << endl;
        printf("Case %d: %d\n",i+1,maxi);
        // reset();
    }

    return 0;
}

