#include<bits/stdc++.h>
using namespace std;

map<string,string> par;
int res,c,c2;
struct node
{

    char a[51],b[51];
    int cost;

};

bool cmp(node A,node B)
{
    return A.cost<B.cost;
}


string Find(string r)
{
    if(par[r]==r)
        return r;
    else
        return par[r]=Find(par[r]);
}

void Union(string a,string b,int cost)
{
    if(Find(a)!=Find(b))
    {
        par[Find(a)]=par[b];
        res+=cost;
        c2++;
    }
}
int main()
{
    int t,m;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);

    for(int i=1; i<=t; i++)
    {
        scanf("%d",&m);
        node data[100];
        //bool c

        for(int j=0; j<m; j++)
        {
            scanf("%s %s %d",&data[j].a,&data[j].b,&data[j].cost);
            if(par[data[j].a]=="")
                par[data[j].a]=data[j].a,c++;
            if(par[data[j].b]=="")
                par[data[j].b]=data[j].b,c++;
        }
        sort(data,data+m,cmp);


        //   cout << c << endl;
        for(int j=0; j<m; j++)
        {
            //printf("%s %s %d\n",data[j].a,data[j].b,data[j].cost);
            Union(data[j].a,data[j].b,data[j].cost);

            //.  if()
        }
        if(c2==c-1)
            printf("Case %d: %d\n",i,res);
        else
            printf("Case %d: Impossible\n",i);
        par.clear();
        res=0,c=0,c2=0;
    }
}
