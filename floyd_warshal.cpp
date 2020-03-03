
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
ll graph[1000][1000],dist[1000][1000];
int main() {
    ll n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    	{
    		cin>>graph[i][j];
    	}
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    	{
    		dist[i][j]=graph[i][j];
    	}

    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			for(k=0;k<n;k++)
    			{
    				if(dist[j][k]>dist[j][i]+dist[i][k])
    					dist[j][k]=dist[j][i]+dist[i][k];
    			}
    		}
    	}
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    	    {
    		    if(dist[i][j]==123456789)
    			    cout<<"INF"<<" ";
    		    else
    		    cout<<dist[i][j]<<" ";
    	    }
    	    cout<<endl;
    	}

    return 0;
}
// 4
// 0 5 123456789 10
// 123456789 0 3 123456789
// 123456789 123456789 0 1
// 123456789 123456789 123456789 0

// ans 
// 0 5 8 9 
// INF 0 3 4 
// INF INF 0 1 
// INF INF INF 0 