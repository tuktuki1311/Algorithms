#include<bits/stdc++.h>
using namespace std;



#define MAXC 1010
char B[MAXC];
 string A="hello";
int lenA=A.size(),lenB;
int dp[MAXC][MAXC];
int calcLCS(int i,int j)
{
    if(i==lenA || j==lenB)
     return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans;
    if(A[i]==B[j])
      return  dp[i][j]=1+calcLCS(i+1,j+1);
    else
    {
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        return dp[i][j]=max(val1,val2);
    }
}
int main()
{
    int n;
    cin >> n;
     while(n--)
    {
        string b;
        cin >> b;
        memset(dp,-1,sizeof(dp));
        lenB=b.size();
        int r=calcLCS(0,0);
        cout << r << " " << lenA << endl;
        if(r==lenA)

        printf("YES\n");
        else
        printf("NO\n");

    }
    return 0;

}
