#include <iostream>
using namespace std;
#include<bits/stdc++.h>
vector <int> graph[10000];
stack <int> s;
void toposort(int node,bool visited[])
{
    int i;
    visited[node]=true;
    for(auto x:graph[node])
    {
        if(visited[x]==false)
        toposort(x,visited);
    }
    s.push(node);
}
int main() {
	int v,e,i,e1,e2;
	cin>>v>>e;
	bool visited[v+5];
	for(i=0;i<e;i++)
	{
	    cin>>e1>>e2;
	    graph[e1-1].push_back(e2-1);
	}
	for(i=0;i<v+5;i++)
	visited[i]=false;
	for(i=0;i<v;i++)
	{
	    if(visited[i]==false)
	    toposort(i,visited);
	}
	while(!s.empty())
	{
	    cout<<s.top()<<" ";
	    s.pop();
	}
	return 0;
}