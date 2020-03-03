/*
susheel_7
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(a) push_back(a)
# define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
int main()
{
    int i,a,b,c,V,E;
    cin>>V>>E;
    vector <pair<int,int>> vec[V];
    vector <pair<int,int>> :: iterator it;
    for(i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
        vec[b].push_back(make_pair(a,c));
    }
    // for(int i=0;i<V;i++)
    // {
    //     for(it=vec[i].begin(); it!=vec[i].end();it++)
    //     cout << it->first << " " << it->second <<endl;
    // }
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; 
  
    int src = 0;
    vector<int> key(V, INF);
    // To store parent array which in turn store MST 
    vector<int> parent(V, -1); 
  
    // To keep track of vertices included in MST 
    vector<bool> inMST(V, false); 
    
    pq.push(make_pair(0,src));
    key[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        inMST[u]=true;
        for(auto x: vec[u])
        {
            int v=x.first;
            int weight=x.second;
            if(inMST[v]==false&&key[v]>weight)
            {
                key[v]=weight;
                pq.push(make_pair(key[v],v));
                parent[v]=u;
            }
        }
    }
    for (int i = 1; i < V; ++i) 
        printf("%d - %d\n", parent[i], i); 
    return 0;
}