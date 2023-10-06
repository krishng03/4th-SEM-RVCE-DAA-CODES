#include <stdio.h>

int n, sourceNode, cost[10][10], d[10], v[10];

void djikstra()
{
    int min, i, j, u;
    v[sourceNode] = 1;
    for(i = 1; i <= n; i++)
    {
        min = 999;
        for(j = 1; j <= n; j++)
        {
            if(v[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        v[u] = 1;
        for(j = 1; j <= n; j++)
        {
            if(v[j] == 0 && d[j] > d[u] + cost[u][j])
                d[j] = d[u] + cost[u][j];
        }
    }
}

int main()
{
    printf("Read number of Nodes :\n>>> ");
    scanf("%d", &n);
    printf("Read Source Node :\n>>> ");
    scanf("%d", &sourceNode);
    printf("Read Adjacency Matrix of Graph :\n>>> ");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = cost[sourceNode][i];
        v[i] = 0;
    }
    djikstra();
    for(int i = 1; i <= n; i++)
        printf("%d --> %d = %d\n", sourceNode, i, d[i]);
    return 0;
}