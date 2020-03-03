
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
int root(int a[],int v)
{
	if(a[v]==v)
		return v;
	else
	a[v]=root(a,a[v]);
	return a[v];

}
void unionfind(int a[],int v1,int v2)
{
	ll s1=root(a,v1);
	ll s2=root(a,v2);
	// if(s1==s2)
	// 	cout<<" Cycle detected"<<endl;
	if(s1!=s2)
	{
		a[s2]=s1;
	}
}
int main() {
    int V,E,i,v1,v2;
    cin>>V>>E;
    int a[V+5];
    for(i=0;i<=V;i++)
    	a[i]=i;
    for(i=0;i<E;i++)
    {
    	cin>>v1>>v2;
    	unionfind(a,v1,v2);
    }
    for(i=1;i<=V;i++)
    	cout<<a[i]<<" ";
    return 0;
}