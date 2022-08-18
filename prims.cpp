#include<bits/stdc++.h>
using namespace std;
#define V 5
int minn(int key[],bool mst[])
{
    int m=INT_MAX;
    int mind=0;
    for (int i = 0; i < V; i++)
    {
        if(key[i] > m && mst[i]==false)
        {
            m=key[i];
            mind=i;
        }
    }

    return mind;
    
}
void printmst(int graph[][V],int parent[])
{
for(int i=1;i<V;i++)
{
    cout<<parent[i]<<" - "<<i<<" weight ="<<graph[i][parent[i]]<<endl;
}
}

void prims(int graph[][V])
{
    int parent[V];
    bool mst[V]={false,false,false,false,false};
    int key[V]={0,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    parent[0]=-1;
    for(int i=0;i<V-1;i++)
    {
        int min_index=minn(key,mst);
        mst[min_index]=true;

        for(int j=0;j<V;j++)
        {
            if(graph[i][j] && !mst[j] && graph[i][j]<key[j])
            {
                key[j]=graph[i][j];
                parent[j]=i;
            }
        }
    }
    printmst(graph,parent);

}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } };
prims(graph);
    
    return 0;
}