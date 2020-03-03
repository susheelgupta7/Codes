#include <iostream>
#include<bits/stdc++.h>
#include <deque> 
using namespace std;
vector <int> v[1005];
void DFS(int start,int n)
{
    bool visited[n+5];
    for(int i=0;i<n;i++)
    visited[i]=false;
    stack <int> s;
    s.push(start);
    visited[start]=true;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        int t=s.top();
        s.pop();
        for(int i=0;i<v[t].size();i++)
        {
            if(!visited[v[t][i]])
            {
                s.push(v[t][i]);
                visited[v[t][i]]=true;
            }
        }
    }
}
int main()
{
    int n,i,j,a,b,q;
    cin>>n;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=0;i<V;i++)
    {
	if(!visited[i])
        DFS(i);
    }
    return 0;
}
    // DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
    //   let S be stack
    //   S.push( s )            //Inserting s in stack 
    //   mark s as visited.
    //   while ( S is not empty):
    //       //Pop a vertex from stack to visit next
    //       v  =  S.top( )
    //      S.pop( )
    //      //Push all the neighbours of v in stack that are not visited   
    //     for all neighbours w of v in Graph G:
    //         if w is not visited :
    //                  S.push( w )         
    //                 mark w as visited


