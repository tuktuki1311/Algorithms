#include<bits/stdc++.h>
#define MAX 105

using namespace std;

queue <int > q;
int n,m,c;
char arr[MAX][MAX];
bool vist[MAX][MAX];
/*int dr[]={0,0,-1,1,-1,1,1};
int dc[]={-1,1,0,0,-1,1,-1,1};*/

int dr[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dc[] = {0, 1, 0, -1, 1, -1, -1, 1};


void BFS()
{
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();

        for(int k=0; k<8; k++)
        {
            int i = x+dr[k];
            int j = y+dc[k];

            if(i>=0 && i<m && j>=0 && j<n && arr[i][j]=='@' && vist[i][j]==false)
            {
                vist[i][j]=true;
                q.push(i);
                q.push(j);
            }
        }

    }
}
int main()
{
    while( cin >> m >> n)
    {
        if(n==0 || m==0)
            break;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin >> arr[i][j];


        c=0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]=='@' && vist[i][j]==false)
                {
                    q.push(i);
                    q.push(j);
                    vist[i][j]=true;
                    c++;
                   //cout << "Cnt is: " << c << endl;
                    BFS();
                }
            }
        }
        cout << c << endl;

        memset(vist, 0, sizeof(vist));
    }
return 0;
}
