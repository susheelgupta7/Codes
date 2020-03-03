#include <iostream>
#include<bits/stdc++.h>
#include <deque> 
using namespace std;
vector <int> v[1005];
void BFS(int start,int n)
{
    bool visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    queue <int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int currVertex = q.front();
        cout<<currVertex<<" ";
        int s=q.front();
        q.pop();
        for(int i =0; i<v[s].size(); i++)
        {
            int adjvertex=v[s][i];
            if(!visited[adjvertex])
            {
                visited[adjvertex] = true;
                q.push(adjvertex);
            }
        }
    }
}
int main()
{
    int n,i,j,a,b;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS(0,n);
    return 0;
}