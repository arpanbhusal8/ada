#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
class bfs
{
public:
    vector<int> createbfs(int fnode, vector<int> adj[])
    {
        vector<int> visited(5, 0);
        vector<int> storebfs;
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while (!q.empty())
        {
            int node = q.front();
            storebfs.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return storebfs;
    }
};

int main()
{
    vector<int> adj[6];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    vector <int> temp=adj[0];
    
    bfs ans;
    int a=1;//first element in dfs
    vector <int> sol;
    sol = ans.createbfs(a,adj);


    for (auto it : sol)
    {
        cout << it;
    }
    return 0;
}