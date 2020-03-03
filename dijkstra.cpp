#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
vector <pair<int,int>> graph[100005];
bool visited[100005];
ll dist[100005],V;
void Dijkstra(int vertex)
{
	for(int i=0;i<V;i++)
    	dist[i]=INF;
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(vertex,0));
	dist[0]=0;

	while(!pq.empty())
	{
		ll u=pq.top().first;
		pq.pop();
		for(auto x:graph[u])
		{
			ll v=x.first;
			ll weight=x.second;
			//cout<<v<<" "<<weight<<endl;
			if(dist[v]>dist[u]+weight)
			{
				dist[v]=dist[u]+weight;
				pq.push(make_pair(v,dist[v]));
			}	
		}
	}
	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
}

int main() {
    int E,i,v1,v2,w;
    cin>>V>>E;
    for(i=0;i<E;i++)
    {
    	cin>>v1>>v2>>w;
    	graph[v1].push_back(make_pair(v2,w));
    	graph[v2].push_back(make_pair(v1,w));
    }
    Dijkstra(0);
    return 0;
}