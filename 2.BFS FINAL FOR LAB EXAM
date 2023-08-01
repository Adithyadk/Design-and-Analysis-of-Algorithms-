#include<stdio.h>
#include<stdlib.h>
int a[10][10],visited[10],n,parent[10],acyclic=1;
int count=0,flag=0;
struct q
{
    int *arr, f, r, c;
};
void init(struct q *qu, int n)
{
    qu->arr = malloc(n * sizeof(int));
    qu->f = 0;
    qu->r = -1;
    qu->c = 0;
}
void insert(struct q *qu, int k)
{
    qu->arr[++qu->r] = k;
    qu->c++;
}
void del(struct q *qu)
{
    printf("%d ",qu->arr[qu->f]);
    qu->f++;
    qu->c--;
}
int isEmpty(struct q *qu)
{
    if (qu->c == 0)
        return 1;
    else
        return 0;
}
void genData(int ch) //ch=0 for worst,ch=1 for best
{
    printf("Graph is\n");
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && ch==0)
                a[i][j] = 0;
            else if(ch==0)
                a[i][j] = 1;
            else if(j-1 == i && ch==1) a[i][j] = 1;
            else if(i-1==j && ch==1) a[i][j]=1;
            else a[i][j]=0;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void bfs(int v, int P,struct q* qu)
{
    int i;
    visited[v]=1;
    insert(qu,v);
    while(qu->c!=0){
        v=qu->arr[qu->f];
        for(i=0;i<n;i++)
        {
            if(a[v][i])
            {
                count++;
                if(visited[i]==0) 
                {
                    count++;
                    visited[i]=1;
                    insert(qu,i);
                    parent[i]=v;
                }
                else
                {
                    if(parent[v]!=i)
                    {
                        acyclic=0;
                    }
                }
            }
        }
        del(qu);
    }
}
void connectandcyclic()
{
    if(flag<=1)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");
    if(acyclic)
        printf("Graph is acyclic\n");
    else
        printf("Graph is cyclic\n");
}

void main()
{
    FILE *fptr=fopen("dfs.txt","a");
    int i,j;
    int start;
    n=4;
    struct q *qu=malloc(sizeof(struct q));
    while(n<6){
        init(qu,n);
        //best case
        for(i=0;i<=n;i++)
            visited[i]=0;
        genData(1);
        printf("Enter starting vertex ");
        scanf("%d",&start);
        count=0,flag=0,acyclic=1;
        for (i=start;i<(n+start);i++)
        { 
            if(visited[i%n]==0)
            {
	            flag+=1;
	            printf("Component\n");
                bfs(i%n,-1,qu);
            }
        }
        connectandcyclic();
        fprintf(fptr,"%d\t%d\t",n,count);

        //worst case
        count=0,flag=0,acyclic=1;
        for(i=0;i<n;i++)
            visited[i]=0;
        genData(0);
        printf("Enter starting vertex ");
        scanf("%d",&start);
        for (i=start;i<(n+start);i++)
        { 
            if(visited[i%n]==0)
            {
	            flag+=1;
	            printf("Component\n");
                bfs(i%n,-1,qu);
            }
        }
        connectandcyclic();
        fprintf(fptr,"%d\n",count);
        n=n+1;
    }
}
