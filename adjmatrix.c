#include<stdio.h>
#include<stdlib.h>
int ver=5;
void createadjmatr(int arr[][2],int adjmatrix[][ver+1],int edges)
{
    for(int i=0;i<ver+1;i++)
    {
        for(int j=0;j<ver+1;j++)
        adjmatrix[i][j]=0;
    }
    for(int i=0;i<edges;i++)
    {
        int x=arr[i][0];
        int y=arr[i][1];

        adjmatrix[y][x]=1;
        adjmatrix[x][y]=1;
        
    }
    for (int i = 1; i < ver+1; i++)
    {
        for (int j = 1; j < ver+1; j++)
        {
        printf("%d   ",adjmatrix[i][j]);
        }
        printf("\n");
        
    }
    
}

int main()
{
    int arr[][2]={{ 1, 2 }, { 2, 3 }, 
            { 4, 5 }, { 1, 5 } };
    int edge=sizeof(arr)/sizeof(arr[0]);
    int adjmatrix[ver+1][ver+1];
    createadjmatr(arr,adjmatrix,edge);

    return 0;
}