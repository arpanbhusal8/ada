#include<bits/stdc++.h>
using namespace std;
#define INF 9999
#define V 4
    void dijsktra(int graph[][V])
    {
        int mindistmatr[V][V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                mindistmatr[i][j]=graph[i][j];
            }
        }
        
        for(int k=0;k<V;k++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    if(mindistmatr[i][j]>(mindistmatr[i][k]+mindistmatr[k][j])&& (mindistmatr[i][k]!=INF && mindistmatr[k][j]!=INF ))
                    mindistmatr[i][j]=mindistmatr[i][k]+mindistmatr[k][j];
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(mindistmatr[i][j]==9999)
                    cout<<"INF  ";
                    else
                cout<<mindistmatr[i][j]<<"    ";
            }
            cout<<endl;
            
        }
    }

int main()
{
      int graph[V][V] = { { 0, 5, INF, 10 },
                          { INF, 0, 3, INF },
                          { INF, INF, 0, 1 },
                          { INF, INF, INF, 0 } };
        dijsktra(graph);


    return 0;
}