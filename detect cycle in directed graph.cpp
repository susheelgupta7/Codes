#include <iostream>
using namespace std;
#include<bits/stdc++.h>
vector <int> graph[10000];
bool detectcycle(int node,bool visited[],bool rec_stack[])
{   
    if(visited[node]==false)
    {
        visited[node]=true;
        rec_stack[node]=true;    
        for(int i=0;i<graph[node].size();i++)    
        {        
            if(visited[graph[node][i]]==0&&detectcycle(graph[node][i],visited,rec_stack))
            return true;
            else if(rec_stack[graph[node][i]]==1)
            return true;
        }
    }
    rec_stack[node]=false;
    return false;
}
int main() 
{    
    int v,e,idx=0,i,a,b,s=0;    
    cin>>v>>e;    
    for(i=0;i<e;i++)    
    {        
        cin>>a>>b;        
        graph[a-1].push_back(b-1);    
    }    
    bool visited[v+5];    
    bool rec_stack[v+5];    
    for(i=0;i<v+5;i++)    
    visited[i]=false;    
    for(i=0;i<v+5;i++)    
    rec_stack[i]=false;
    for(i=0;i<v;i++)
    {
        s=detectcycle(i,visited,rec_stack);
        if(s==true)
        break;
    }
    cout<<s;
    return 0;
}