
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
struct node{
	int a,b,c,d;
};
struct node1{
	int x1,x2;
	bool operator<(const node1& rhs) const
	{
		return x1<rhs.x1;
	}
}
int comp(node a1,node a2)
{
	if(a1.a!=a2.a)
		return a1.a<a2.a;
	else if(a1.b!=a2.b)
		return a1.b<a2.b;
	else
		return a1.c<a2.c;
}
int main() {
     //priority_queue<int ,vector<int>,greater<int>> pq;
    int n,i;
    
    cin>>n;
        struct node pr[n+5];
    for(i=0;i<n;i++)
    {
    	cin>>pr[i].a>>pr[i].b>>pr[i].c>>pr[i].d;
    }
    sort(pr,pr+n,comp);
    for(i=0;i<n;i++)
    {
    	cout<<pr[i].a<<" "<<pr[i].b<<" "<<pr[i].c<<" "<<pr[i].d<<endl;
    }
    return 0;
}