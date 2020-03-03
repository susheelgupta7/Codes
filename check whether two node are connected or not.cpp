#include <iostream>
using namespace std;
#include<bits/stdc++.h>
vector <int> dsu[10000];
vector <int> graph[10000];
void graphreach(int node,bool visited[],int idx)
{
    visited[node]=true;
    dsu[idx].push_back(node);
    for(int i=0;i<graph[node].size();i++)
    {
        if(visited[graph[node][i]]==false)
        graphreach(graph[node][i],visited,idx);
    }
}
int main() {
	int v,e,idx=0,i,a,b;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
	    cin>>a>>b;
	    graph[a-1].push_back(b-1);
	    graph[b-1].push_back(a-1);
	}
	bool visited[v+5];
	for(i=0;i<v+5;i++)
	visited[i]=false;
	for(i=0;i<v;i++)
	{
	    if(visited[i]==false)
	    {
	        
	        graphreach(i,visited,idx);
	        idx++;
	    }
	    
	}
	for(i=0;i<idx;i++)
	{
	    for(int j=0;j<dsu[i].size();j++)
	    cout<<dsu[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}