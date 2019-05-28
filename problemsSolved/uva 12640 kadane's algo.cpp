#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll MaxSubArraySum(ll arr[],ll n)
{
    int m,sum=0,leftSum=INT_MIN,rightSum=INT_MIN,ans=0,sum1=0;

    if(n==1)
        return arr[0];

     m=n/2;

    ll left_MSS= MaxSubArraySum(arr,m);
    ll right_MSS= MaxSubArraySum(arr+m,n-m);

    for(ll i=m; i<n; i++)
    {
        sum+=arr[i];
        leftSum=max(sum,leftSum);
    }

    sum=0;

    for(ll i=m-1; i>=0; i--)
    {
        sum+=arr[i];
        rightSum=max(sum,rightSum);
    }

    sum1=leftSum+rightSum;

    ans=max(left_MSS,right_MSS);
    ans=max(ans,sum1);

    return ans;
}

int main()
{
    string number;
    ll arr[100050];

    while(getline(cin,number))
    {
    istringstream is (number);
    ll index=0,cnt;
    while(is >> cnt){
        arr[index++]=cnt;
       // cout << cnt << ' ';
    }
    cnt=MaxSubArraySum(arr,index);
    if(cnt>0)
    cout << cnt << endl;
    else
    cout << 0 << endl;
    }

return 0;
}
