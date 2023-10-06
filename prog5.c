#include <stdio.h>

int n, W, w[10], v[10], x[10] = {0}, V[10][10];

int max(int a, int b)
{
    return a>b?a:b;
}

void objects()
{
    int i = n, j = W, wsum = 0, psum = 0;
    while(i != 0)
    {
        if(V[i][j] != V[i-1][j])
        {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }
    for(int i = 1; i <= n; i++)
    {
        if(x[i] == 1)
        {
            psum += v[i];
            wsum += w[i];
            printf("%d - %d\n", w[i], v[i]);
        }
    }
    printf("--------\n");
    printf("%d - %d\n", wsum, psum);
}

int knapsack()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j= 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else
            {
                if(j - w[i] < 0)
                    V[i][j] = V[i-1][j];
                else
                    V[i][j] = max(V[i-1][j], V[i-1][j-w[i]] + v[i]);
            }
        }
    }
    return V[n][W];
}

int main()
{
    printf("Read the number of objects :\n>>> ");
    scanf("%d", &n);
    printf("Read the Knapsack Capacity :\n>>> ");
    scanf("%d", &W);
    printf("Read the weight of objects :\n>>> ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Read the profit of objects :\n>>> ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    int result = knapsack();
    printf("Max Profit : %d\n\n", result);
    objects();
    return 0;    
}