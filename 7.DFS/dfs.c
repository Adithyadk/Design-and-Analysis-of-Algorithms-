//DFS

#include <stdio.h>
#include <stdlib.h>
int n, count = 0;
int ct = 0, k = 0;
void genData(int a[][n], int size, int ch) // ch=0 for worst,ch=1 for best
{
    printf("Graph is\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j && ch == 0)
                a[i][j] = 0;
            else if (ch == 0)
                a[i][j] = 1;
            else if (j - 1 == i && ch == 1)
                a[i][j] = 1;
            else
                a[i][j] = 0;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void dfs(int a[][n], int i, int s, int visited[], int *c, int comp[], int *cycfg, int p)
{
    if (k == 0 && i != s)
    {
        visited[i] = (*c) * n;
        k = *c;
    }
    else
    {
        *(c) += 1;
        visited[i] = *c;
    }
    printf("%c\t", i + 65);
    comp[k] = i;
    k += 1;
    for (int j = 0; j < n; j++)
    {
        count++;
        if (visited[j] == 0 && a[i][j] == 1)
            dfs(a, j, s, visited, c, comp, cycfg, i);
        else
        {
            if (a[i][j] == 1 && i != p)
                *(cycfg) = 1;
        }
    }
}
void dfs_help(int a[][n], int s, int visited[], int *c, int comp[], int *cycfg)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        comp[i] = 0;
    }
    for (int i = s; (i % (n + 1)) < n; i++)
    {
        i = i % (n + 1);
        if (visited[i] == 0)
        {
            ct += 1;
            k = 0;
            dfs(a, i, s, visited, c, comp, cycfg, -1);
        }
    }
}
void printComponent(int comp[], int visited[], int n)
{
    int i = 0, p = 1;
    while (i < n)
    {
        printf("Component %d is\n", p);
        p++;
        do
        {
            printf("%c\t", comp[i] + 65);
            i++;
        } while (visited[i] <= n && i < n);
        printf("\n");
    }
}
void main()
{
    FILE *f = fopen("dfs_count.txt", "w");
    int c = 0, s, p = 1, cycfg = 0;
    char m;
    n = 4;
    while (n <= 6)
    {
        count = 0, c = 0, p = 1, ct = 0, k = 0, cycfg = 0;
        int a[n][n], b[n][n];
        int visited[n];
        int comp[n];

        // best case
        genData(a, n, 1);
        printf("enter start node.Nodes are A,B...\n");
        scanf(" %c", &m);
        s = m - 65;
        printf("Traversal\n");
        dfs_help(a, s, visited, &c, comp, &cycfg);
        printf("\n");
        if (cycfg == 1)
            printf("Cyclic\n");
        else
            printf("Acyclic\n");
        if (ct > 1)
            printf("Disconnected\n");
        else
            printf("Connected\n");
        printf("Connected components are\n");
        printComponent(comp, visited, n);
        printf("Count : %d", count);
        fprintf(f, "%d\t%d\n", n, count);
        printf("\n");

        // worst case
        count = 0, c = 0, p = 1, ct = 0, k = 0, cycfg = 0;
        genData(b, n, 0);
        printf("enter start node.Nodes are A,B...\n");
        scanf(" %c", &m);
        s = m - 65;
        printf("Traversal\n");
        dfs_help(b, s, visited, &c, comp, &cycfg);
        printf("\n");
        if (cycfg == 1)
            printf("Cyclic\n");
        else
            printf("Acyclic\n");
        if (ct > 1)
            printf("Disconnected\n");
        else
            printf("Connected\n");
        printf("Connected components are\n");
        printComponent(comp, visited, n);
        printf("Count : %d", count);
        fprintf(f, "%d\t%d\n", n, count);
        printf("\n");
        n += 1;
    }
}