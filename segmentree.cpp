
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
ll segtree[100000];
void build(int a[],int start,int end,int node)
{
	if(start==end)
		segtree[node]=a[start];
	else
	{
		int mid=(start+end)/2;
		build(a,start,mid,2*node+1);
		build(a,mid+1,end,2*node+2);
    	segtree[node]=segtree[2*node+1]+segtree[2*node+2];
	}
}
void update(int a[],int start,int end,int value,int idx,int node)
{
	if(start==end)
	{
		a[idx]=value;
		segtree[node]=value;
	}
	else
	{
		ll mid=(start+end)/2;
		if(idx<=mid)
			update(a,start,mid,value,idx,2*node+1);
		else
			update(a,mid+1,end,value,idx,2*node+2);
		segtree[node]=segtree[2*node+1]+segtree[2*node+2];
	}
}
int query(int a[],int start,int end,int l,int r,int node)
{
	if(r<start||l>end)
		return 0;
	if(l<=start&&r>=end)
		return segtree[node];
	else
	{
		ll mid=(start+end)/2;
		ll p1=query(a,start,mid,l,r,2*node+1);
		ll p2=query(a,mid+1,end,l,r,2*node+2);
		return p1+p2;
	}
}
int main() {
    int n,i;
    cin>>n;
    int a[n+5];
    for(i=0;i<n;i++)
    	cin>>a[i];
    build(a,0,n-1,0);
    for(i=0;i<9;i++)
    	cout<<segtree[i]<<" ";
    cout<<endl;
    update(a,0,n-1,7,2,0);
    for(i=0;i<9;i++)
    	cout<<segtree[i]<<" ";
    cout<<endl;
    cout<<query(a,0,n-1,2,4,0);
    return 0;
}