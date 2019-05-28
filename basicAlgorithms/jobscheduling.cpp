#include<bits/stdc++.h>
using namespace std;

struct job
{
    char id;
    int deadline;
    int profit;

    bool operator<(const job &p)const
    {
        return profit > p.profit;
    }
};
vector<job>sequence;
bool slot[50];
int res[50];


int printJobScheduling(int n)
{
   sort(sequence.begin(),sequence.end());
   int pro=0;
    for (int i=0; i<n; i++)
    {
       int index=min(n,sequence[i].deadline)-1;
       for (int j=index; j>=0; j--)
       {
          if (slot[j]==false)
          {
             res[j] = i;
             slot[j] = true;
             pro+=sequence[i].profit;
             break;
          }
       }
    }

    cout << "sequence is: " ;
    for (int i=0; i<n; i++)
       if (slot[i])
         cout << sequence[res[i]].id << " ";
    return pro;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char id;
        int deadline,profit;

        cin>>id>>deadline>>profit;

        job data;
        data.id=id;
        data.deadline=deadline;
        data.profit=profit;

        sequence.push_back(data);
    }
    int pro=printJobScheduling(n);
    cout << endl;
    cout << "profit is: " << pro << endl;
}
