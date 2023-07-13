//DFS Topological Sorting.

#include <stdio.h>
#include<stdlib.h>
int count;
int n,k=0;
int dfs(int a[][n],int visited[],int topoorder[],int i,int p[])
{
    if(visited[i]==0) visited[i]=1;
    p[i]=1;
    for(int j=0;j<n;j++)
    {
        count++;
        if(a[i][j]==1)
           {
            if(visited[j]==1 && p[j]==1) return 0;
            else
            {
                if(visited[j]==0)
                {
                    if(dfs(a,visited,topoorder,j,p)==0) return 0;
                }
            }
        }
    }
    p[i]=0;
    topoorder[k]=i;
    k+=1;
    return 1;
}
int topo(int a[][n],int visited[],int topoorder[],int p[])
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
       {
        if(visited[i]%(n+1)==0)
        { 
         if(dfs(a,visited,topoorder,i,p)==0) return 0;
        }
    }
    return 1;
}
void main()
{
    count=0;
    FILE *f;
    f = fopen("dfstopo.txt", "a");
    printf("Enter no. of nodes\n");
    scanf("%d",&n);
    int a[n][n];
    int topoorder[n];
    printf("Enter graph\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
     {
      scanf("%d",&a[i][j]);
      }
    }
    int visited[n];
    int p[n];
    int r=topo(a,visited,topoorder,p);
    fprintf(f, "%d\t%d\n", n, count);
    if(r!=0)
    {
        for(int i=n-1;i>=0;i--) printf("C%d\t",topoorder[i]);
        printf("\n");  
    }
    else printf("Cyclic graph\n");
}