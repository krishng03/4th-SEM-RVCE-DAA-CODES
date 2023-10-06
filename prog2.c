#include <stdio.h>
#define SIZE 100

int stack[SIZE], visited[SIZE], G[SIZE][SIZE], top, size;

void topologicalOrdering(int n)
{
    int i;
    visited[n] = 1;
    if(visited[n])
    {
        for(i = 1; i <= size; i++)
        {
            if(G[n][i] == 1 && visited[i] == 0)
            {
                topologicalOrdering(i);
            }
        }
        if(i > size)
            stack[++top] = n;
    }
}

int main()
{
    top = -1;
    printf("Read Size :\n>>> ");
    scanf("%d", &size);
    printf("Read Graph :\n>>> ");
    for(int i = 1; i <= size; i++)
    {
        visited[i] = 0;
        for(int j = 1; j <= size; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    topologicalOrdering(1);
    printf("The Topological Ordering of the given graph is :\n>>> ");
    while(top!=0)
    {
        printf("%d --> ", stack[top--]);
    }
    printf("%d\n", stack[0]);
    return 0;
}

/*
0 1 1 0 0
0 0 0 0 1
0 0 0 0 1
0 0 0 0 0
0 0 0 1 0
*/