/*
susheel_7
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
vector <int> graph[100005];
vector <int> grapht[100005];
bool visited[100005];
stack <int> st;
queue <int> q;
stack <int> stac;
void toposort(int vertex)
{

  visited[vertex]=true;
  for(auto x:graph[vertex])
  {
    if(!visited[x])
      toposort(x);
  }
  st.push(vertex);
}
void dfs(int vertex)
{
  stac.push(vertex);
  visited[vertex]=true;
  while(!stac.empty())
  {
    cout<<stac.top()<<" ";
    ll v=stac.top();
    stac.pop();
    for(auto x:grapht[v])
    {
      if(!visited[x])
      {
        visited[x]=true;
        stac.push(x);
      }
    }
  }
}
int main()
{
    int V,E,i,v1,v2;
    cin>>V>>E;
    for(i=0;i<V+5;i++)
      visited[i]=false;
    for(i=0;i<E;i++)
    {
      cin>>v1>>v2;
      graph[v1].push_back(v2);
      grapht[v2].push_back(v1);
    }
    for(i=0;i<V;i++)
    {
      if(!visited[i])
        toposort(i);
    }
    for(i=0;i<V+5;i++)
      visited[i]=false;
    while(!st.empty())
    {
      ll v=st.top();
      st.pop();
      if (!visited[v])
      {
        /* code */
        dfs(v);
        cout<<endl;
      }
    }
    return 0;
}