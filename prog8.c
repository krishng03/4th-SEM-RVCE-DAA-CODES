#include <stdio.h>
#include <math.h>

int x[10] = {0};
int c = 1;

void printBoard(int n)
{
    printf("Solution %d:\n", c++);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i] == j)
            {
                printf("Q\t");
            }
            else{
                printf("-\t");
            }
        }
        printf("\n");
    }
}

int place(int k, int i)
{
    for(int j = 1; j < k; j++)
    {
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}

void nQueens(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] =i;
            if(k == n)
            {
                printf("\n");
                printBoard(n);
            }
            else
                nQueens(k+1, n);
        }
    }
}

int main()
{
    int n;
    printf("Enter Number of Queens :\n>>> ");
    scanf("%d", &n);
    nQueens(1, n);
    if(c == 1)
        printf("No Solutions!");
    return 0;
}