/*
susheel_7
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(a) push_back(a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
int main()
{
   fast_cin();
   int t,r;
   cin>>t;
   for(r=1;r<=t;r++)
   {
   	ll n,h;
   	cin>>n>>h;
   	ll a[n],b[n],i,j,k;
   	for(i=0;i<n;i++)
   		cin>>a[i];
   	for(i=0;i<n;i++)
   		cin>>b[i];
   	vector<ll> v1,v2;

/////////////////////////code to find sub set sum of a number ;
   	v1.pb(0);
   	v2.pb(0);
   	for(i=0;i<n;i++)
   	{
   		int l=v1.size();
   		for(j=0;j<l;j++)
   		{
   			v1.pb(a[i]+v1[j]);
   		}
}
////////////////////////////////////
   	for(i=0;i<n;i++)
   	{
   		int l=v2.size();
   		for(j=0;j<l;j++)
   		{
   			v2.pb(b[i]+v2[j]);
   		}
   	}
   	sort(v1.begin(),v1.end());
   	sort(v2.begin(),v2.end());
   	ll l=v1.size();
   	ll i1=lower_bound(v1.begin(),v1.end(),h)-v1.begin();
     ll	i2=lower_bound(v2.begin(),v2.end(),h)-v2.begin();
   	for(i=0;i<l;i++)
   		cout<<v1[i]<<" ";
   	ll l1,l2;
   	l1=l-i1;
   	l2=l-i2;
   	// cout<<"Case #"<<r<<": ";
   	// // cout<<endl<<l1<<l2<<i2<<endl;
   	// if(h==0)
   	// cout<<l*l-1<<endl;
   	// else
   	// cout<<l1*l2<<endl;
   }
	return 0;
}