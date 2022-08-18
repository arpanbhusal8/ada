#include<bits/stdc++.h>
using namespace std;
class dfs
{
  void ddfs(vector<int> &visited,int node,vector <int> adj[],vector <int> &storedfs)
  {
    visited[node]=1;
    storedfs.push_back(node);
    for( auto it: adj[node])
    {
      if(!visited[it])
      ddfs(visited,it,adj,storedfs);
    }
  }
public:
vector <int> createdfs(vector <int> adj[],int ver)
{
  vector <int> storedfs;
  vector <int> visited(ver,0);
  for(int i=1;i<ver;i++)
  {
    if(!visited[i])
     ddfs(visited,i,adj,storedfs);
  }
  return storedfs;
}
};
void addEdge(vector<int> adj[],int a,int b)
{
  adj[a].push_back(b);
  adj[b].push_back(a);
}
int main()
{
    vector<int> adj[6];  
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);
    dfs ans;
    vector <int> dfs1;
    dfs1=ans.createdfs(adj,6);
    for(auto it:dfs1)
    cout<<it;
    return 0;
}