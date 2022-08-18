#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int u,v,wt;
    node(int u,int v,int wt)
    {
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};
bool comp(node a,node b)
{
    return a.wt  <b.wt;
}

int finpar(int a,vector <int> &parent)
{
    if(a==parent[a])
    return a;
    else
    return parent[a]=finpar(parent[a],parent);
}
void unionn(int a,int b,vector <int> &rank,vector <int> &parent)
{
    int u =finpar(a,parent);
    int v=finpar(b,parent);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[u]=v;
        rank[v]++;
    }
}
int main()
{
    vector <node> edges;
    int ver=5;
    edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
    sort(edges.begin(),edges.end(),comp);
    vector <int> parent(ver);
    vector <int> rank(ver);
    for(int i=0;i<ver;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    vector<pair<int,int>> mst;
    int cost=0;
    for(auto it:edges)
    {
        if(finpar(it.u,parent)!=finpar(it.v,parent))
        {
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,rank,parent);
        }
    }
    cout<<"total cost of the mst is  ----->"<<cost<<endl;
    for(auto it:mst)
    {
        cout<<it.first<<"------------"<<it.second <<endl;
    }
    return 0;
}