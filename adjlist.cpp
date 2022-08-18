#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void printGraph(vector <int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        cout<<it<<"---------";
    cout<<endl;
    }
}

int main()
{
    vector <int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, 5);
    return 0;
}