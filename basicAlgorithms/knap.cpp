#include<bits/stdc++.h>

using namespace std;

int val[55];
int wt[55];

int knap(int w, int n)
{
    int cost[n+1][w+1];

    for(int i=0; i<=n; i++)
    {
        for(int W=0; W<=w; W++)
        {
            if(i==0 || W==0)
                cost[i][W]=0;

            else if(wt[i-1]<=w)
            {
                int j=w-wt[i];
                cost[i][W]= max(cost[i-1][W],val[i]+cost[i-1][j]);
            }
            else
                cost[i][W]=cost[i-1][W];
        }
    }
    return cost[n][w];
}

int main()
{
    int w,n;
    cin>>n>>w;

    for(int i=0; i<n; i++)
        cin>>val[i]>>wt[i];

    cout << knap(w,n);

    return 0;
}
