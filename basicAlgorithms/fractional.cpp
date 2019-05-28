#include<bits/stdc++.h>

using namespace std;

struct item
{
    int v,w;
    double r;
    bool operator<(const item &p)const
    {
        return r > p.r;
    }
};


vector<item>knap;

double knapsack(int weight)
{
    sort(knap.begin(),knap.end());

   /* for(int i=0; i<knap.size();i++)
        cout << knap[i].r << ' ' << knap[i].v << ' ' <<endl;*/
    //reverse(knap.begin(),knap.end());

    int currWeight=0;
    double currProfit=0.00;

    for(int i=0; i<knap.size(); i++)
    {
       // cout << knap[i].w << endl;
        if(currWeight+knap[i].w<=weight)
        {
            cout << knap[i].w << " ";
            currWeight+=knap[i].w;
            currProfit+=knap[i].v;
           // cout << currWeight <<  ' ' << currProfit<< endl;
        }
        else
        {
            int r=weight-currWeight;
            double remain= ((double) r/ knap[i].w);
            currProfit+=(knap[i].v*remain);
            cout << r << " ";
            //cout << r << ' ' << currProfit << endl;
            break;
        }
    }
    return currProfit;
}
int main()
{
    int n,weight;
    cin>>n>>weight;

    for(int i=0;i<n;i++)
    {
        int v,w;
        double r;
        cin>>v>>w;

        r=((double) v/w);
       // cout << r << endl;

        item data;
        data.v=v;
        data.w=w;
        data.r=r;

       knap.push_back(data);
       //cout <<knap[i].r <<endl;
    }
    cout << "Taken Weights are: ";
    double profit=knapsack(weight);
    cout << "\nprofit is: " << endl;
    cout << profit << endl;
}
