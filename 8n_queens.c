#include <stdio.h>
#include <math.h>

int x[10] = {0}; // Array to store column positions of queens
int c = 1; // Counter for solutions found

// Function to print the chessboard with queen positions
void printBoard(int n)
{
    printf("Solution %d:\n", c++);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
            {
                printf("Q\t"); // Print 'Q' if there's a queen at this position
            }
            else
            {
                printf("-\t"); // Print '-' for empty positions
            }
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at position (k, i)
int place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0; // Check for clashes with other queens in previous rows
    }
    return 1; // Return 1 if the position is safe to place a queen
}

// Function to solve the N-Queens problem using backtracking
void nQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i; // Place a queen at position (k, i)

            if (k == n)
            {
                printf("\n");
                printBoard(n); // If all queens are placed, print the chessboard
            }
            else
                nQueens(k + 1, n); // Recursively try placing queens in the next row

            x[k] = 0; // Remove the queen to backtrack and explore other possibilities
        }
    }
}

int main()
{
    int n;
    printf("Enter Number of Queens :\n>>> ");
    scanf("%d", &n);
    nQueens(1, n); // Call the function to find solutions to the N-Queens problem

    if (c == 1)
        printf("No Solutions!"); // If no solutions were found, print a message

    return 0;
}