/*#include<bits/stdc++.h>
#define MAX 1025
using namespace std;

const int INF = 0x3f3f3f3f;
struct edge{
    int u,v,w;
};

int main()
{
  int n,e,cases=0;
  while(cin>>n>>e){
    if(n==0 && e==0)
        break;
    else{
      int dis[205][205];
      vector<edge>vec;
      map<string,int>city;
      string ss,ff;
      int cost,index=-1;

      for ( int i = 0; i < 205; i++ ) {
            for ( int j = 0; j < 205; j++ ){
                    dis [i] [j] = -1;
            }
            dis [i] [i] = 0;
        }

        for ( int i = 0; i < e; i++ ) {
            cin >> ss >> ff >> cost;
            if ( !city[ss] ) city[ss] = index++;
            if ( !city[ff] ) city[ff] = index++;

            dis [city[ss]] [city[ff]] = cost;
            dis [city[ff]] [city[ss]] = cost;
        }

        for ( int k = 1; k <= n; k++ ) {
            for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ )
                    dis [i] [j] = dis [j] [i] = max (dis [i] [j], min (dis [i] [k], dis [k] [j]));
            }
        }


        string source, dest;
        cin >> source >> dest;
        printf ("Scenario #%d\n", ++cases);
        printf ("%d tons\n\n", dis[city[source]][city[dest]]);



    }
  }
return 0;
}*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;


int main ()
{
    int n, r;
    int cases = 0;

    while ( scanf ("%d %d", &n, &r) ) {
        if ( n == 0 && r == 0 ) break;

        map <string, int> cityIndex;
        string first, second;
        int cost;
        int index = 1;

        int d [205] [205];

        for ( int i = 0; i < 205; i++ ) {
            for ( int j = 0; j < 205; j++ ) d [i] [j] = -1;
            d [i] [i] = 0;
        }

        for ( int i = 0; i < r; i++ ) {
            cin >> first >> second >> cost;
            if ( !cityIndex [first] ) cityIndex [first] = index++;
            if ( !cityIndex [second] ) cityIndex [second] = index++;

            d [cityIndex [first]] [cityIndex [second]] = cost;
            d [cityIndex [second]] [cityIndex [first]] = cost;
        }

        for ( int k = 1; k <= n; k++ ) {
            for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ )
                    d [i] [j] = d [j] [i] = max (d [i] [j], min (d [i] [k], d [k] [j]));
            }
        }


        string source, dest;
        cin >> source >> dest;
        printf ("Scenario #%d\n", ++cases);
        printf ("%d tons\n\n", d [cityIndex[source] ] [cityIndex [dest]]);
    }

    return 0;
}
