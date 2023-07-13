//BFS

#include <stdio.h>
#include <stdlib.h>
int n, count = 0;
int ct = 1, k = 0;
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
void bfs(int a[][n], int i, int s, int visited[], int *c, struct q *qu, int comp[], int pr[], int *cycfg)
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
    insert(qu, i);
    while (isEmpty(qu) != 1)
    {
        i = qu->arr[qu->f];
        for (int j = 0; j < n; j++)
        {
            count++;
            if (visited[j] == 0 && a[i][j] == 1)
            {
                *(c) += 1;
                visited[j] = *c;
                insert(qu, j);
                pr[j] = i;
            }
            else
            {
                if (a[i][j] == 1 && pr[i] != j)
                    *(cycfg) = 1;
            }
        }
        printf("%c\t", i + 65);
        comp[k] = i;
        k += 1;
        del(qu);
    }
}
void bfs_help(int a[][n], int s, int visited[], int *c, struct q *qu, int comp[], int pr[], int *cycfg)
{
    for (int i = 0; i < n; i++)
    {
        comp[i] = 0;
        visited[i] = 0;
        pr[i] = 0;
    }
    for (int i = s; (i % (n + 1)) < n; i++)
    {
        i = i % (n + 1);
        if (visited[i] == 0)
        {
            ct += 1;
            k = 0;
            bfs(a, i, s, visited, c, qu, comp, pr, cycfg);
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
    FILE *f = fopen("bfs_count.txt", "w");
    int c = 0, s, cycfg = 0;
    char m;
    n = 4;
    struct q *qu = malloc(sizeof(struct q));
    while (n <= 6)
    {
        count = 0, c = 0, ct = 0, k = 0, cycfg = 0;
        init(qu, n);
        int a[n][n], b[n][n];
        int visited[n];
        int comp[n];
        int pr[n];

        // best case
        genData(a, n, 1);
        printf("enter start node\n");
        scanf(" %c", &m);
        s = m - 65;
        printf("Traversal\n");
        bfs_help(a, s, visited, &c, qu, comp, pr, &cycfg);
        printf("\n");
        int i = 0;
        if (ct > 1)
            printf("Disconnected\n");
        else
            printf("Connected\n");
        printf("Connected components are\n");
        printComponent(comp, visited, n);
        c = 0;
        if (cycfg == 1)
            printf("Cyclic\n");
        else
            printf("Acyclic\n");
        printf("Count : %d", count);
        fprintf(f, "%d\t%d\n", n, count);
        free(qu->arr);

        // worst case
        init(qu, n);
        count = 0, c = 0, ct = 0, k = 0, cycfg = 0;
        genData(b, n, 0);
        printf("enter start node\n");
        scanf(" %c", &m);
        s = m - 65;
        printf("Traversal\n");
        bfs_help(b, s, visited, &c, qu, comp, pr, &cycfg);
        i = 0;
        if (ct > 1)
            printf("Disconnected\n");
        else
            printf("Connected\n");
        printf("Connected components are\n");
        printComponent(comp, visited, n);
        c = 0;
        if (cycfg == 1)
            printf("Cyclic\n");
        else
            printf("Acyclic\n");
        n += 1;

        free(qu->arr);
        printf("Count : %d", count);
        fprintf(f, "%d\t%d\n", n, count);
        printf("\n");
    }
}