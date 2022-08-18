#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int main()
{
    int p[]={0,1,2,5,6};
    int w[]={0,2,3,4,5};
    int size=sizeof(p)/sizeof(p[0]);
    int limit=8;
    int total_obj=4;
    int k[size+1][limit+1];
    for(int i=0;i<=size;i++)
    {
        for (int j = 0; j <= limit; j++)
        {
            if(i==0||j==0)
            k[i][j]=0;
            else if(w[i-1]<=j)
            {
                k[i][j]=max(p[i]+k[i-1][j-w[i]],k[i-1][j]);
            }
            else
            {
                k[i][j]=k[i-1][j];
            }
        }        
    }
    cout<<"optimal profit-->"<<k[size-1][limit-1]<<endl;
    int i=size;
    int j=limit;
    while(i>0 && j>0)
    {
        if(k[i][j]==k[i-1][j])
        {
            cout<<i<<"=0"<<endl
            ;i--;
        }
        else
        {
            cout<<i<<"=1 "<<endl;
            i--;
            j=j-w[i];
        }
    }
}
