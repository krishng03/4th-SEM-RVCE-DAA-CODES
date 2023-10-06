#include <stdio.h>

int n, W, w[10], v[10], x[10] = {0}, V[10][10]; // Variables for Knapsack problem

// Function to calculate the maximum of two integers
int max(int a, int b)
{
    return a > b ? a : b;
}

// Function to print the selected objects in the Knapsack
void objects()
{
    int i = n, j = W, wsum = 0, psum = 0;

    // Backtrack to find the selected objects
    while (i != 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }

    // Print the selected objects and their weights and profits
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            psum += v[i];
            wsum += w[i];
            printf("%d - %d\n", w[i], v[i]);
        }
    }

    printf("--------\n");
    printf("%d - %d\n", wsum, psum); // Print the total weight and profit of selected objects
}

// Function to solve the 0/1 Knapsack problem
int knapsack()
{
    // Fill the V table to calculate the maximum profit
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                V[i][j] = 0; // Base case: no objects or no capacity
            else
            {
                if (j - w[i] < 0)
                    V[i][j] = V[i - 1][j]; // If current object doesn't fit, take the value from the above row
                else
                    V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]); // Take the maximum of two cases: with or without the current object
            }
        }
    }

    return V[n][W]; // Return the maximum profit
}

int main()
{
    printf("Read the number of objects :\n>>> ");
    scanf("%d", &n);
    printf("Read the Knapsack Capacity :\n>>> ");
    scanf("%d", &W);
    printf("Read the weight of objects :\n>>> ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Read the profit of objects :\n>>> ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    int result = knapsack(); // Solve the Knapsack problem
    printf("Max Profit : %d\n\n", result); // Print the maximum profit

    objects(); // Print the selected objects in the Knapsack
    return 0;
}