
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
ll V,E;
ll dist[100005];
struct n {
	int src,des,weight;
};

   struct n node[100005];

void Bellmanford(int vertex)
{
	int i,j;
	for(i=0;i<V;i++)
    dist[i]=INF;
	dist[vertex]=0;
	for(i=1;i<V;i++)
	{
		for(j=0;j<E;j++)
		{
			ll u=node[j].src;
			ll v= node[j].des;
			ll w=node[j].weight;
			if((dist[u]+w<dist[v])&&dist[u]!=INF)
				dist[v]=dist[u]+w;
		}
	}
	for(i=0;i<V;i++)\
		cout<<dist[i]<<" ";

	/////checking whether graph contain negative cycle
	for(j=0;j<E;j++)
		{
			ll u=node[j].src;
			ll v= node[j].des;
			ll w=node[j].weight;
			if((dist[u]+w<dist[v])&&dist[u]!=INF)
				{
					cout<<"negative cycle exist"<<endl;
				}
		}

}
int main() {

   int i;
   cin>>V>>E;

   for(i=0;i<E;i++)
   {
   	cin>>node[i].src>>node[i].des>>node[i].weight;
   }
   Bellmanford(0);
    return 0;
}