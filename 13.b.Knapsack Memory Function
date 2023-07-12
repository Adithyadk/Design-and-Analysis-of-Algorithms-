//13.b.Knapsack Memory Function
#include <stdio.h>
#include <stdlib.h>
int i, j, n, c, count = 0;
int f[10][10], w[10], v[10];
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}
void composition()
{
    int num = 0;
    int subset[n];
    j = c;
    for (i = n; i >= 1; i--)
    {
        if (f[i][j] != f[i - 1][j])
        {
            subset[num++] = i;
            j -= w[i];
        }
    }
    printf("Composition is : ");
    for (i = 0; i < num; i++)
        printf("%d ", subset[i]);
    printf("\n");
}
int mfk(int i, int j)
{
    if (f[i][j] == -1)
    {
        count++;
        int value;
        if (j - w[i] >= 0)
            value = maximum(mfk(i - 1, j), v[i] + mfk(i - 1, j - w[i]));
        else
            value = mfk(i - 1, j);
        f[i][j] = value;
        return f[i][j];
    }
}

int main()
{
    printf("Enter the number of items : ");
    scanf("%d", &n);
    printf("Enter the Capacity : ");
    scanf("%d", &c);
    printf("Enter the Items' Weights and Value\n");
    printf("Item\tWeight\tValue\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", i);
        scanf("%d\t%d", &w[i], &v[i]);
    }
    for (i = 0; i <= n; i++)
        f[i][0] = 0;
    for (j = 1; j <= c; j++)
        f[0][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= c; j++)
            f[i][j] = -1;
    printf("Optimal Solution : %d\n", mfk(n, c));
    composition();
    printf("Operation Count : %d\n", count);
    return 0;
}
