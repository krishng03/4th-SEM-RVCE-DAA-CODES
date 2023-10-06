#include <stdio.h>
#define SIZE 100

int stack[SIZE], visited[SIZE], G[SIZE][SIZE], top, size;

// Function to perform topological ordering using DFS
void topologicalOrdering(int n)
{
    int i;
    visited[n] = 1; // Mark the current node as visited

    if (visited[n])
    {
        for (i = 1; i <= size; i++)
        {
            // Check for adjacent unvisited nodes with an edge from 'n'
            if (G[n][i] == 1 && visited[i] == 0)
            {
                topologicalOrdering(i); // Recursively visit adjacent nodes
            }
        }
        
        if (i > size)
            stack[++top] = n; // Push the current node onto the stack once all neighbors are visited
    }
}

int main()
{
    top = -1; // Initialize the top of the stack to -1
    printf("Read Size :\n>>> ");
    scanf("%d", &size);
    printf("Read Graph :\n>>> ");
    
    // Read the adjacency matrix representing the graph
    for (int i = 1; i <= size; i++)
    {
        visited[i] = 0; // Initialize all nodes as unvisited
        for (int j = 1; j <= size; j++)
        {
            scanf("%d", &G[i][j]); // Read the edge information (1 if there's an edge, 0 otherwise)
        }
    }

    topologicalOrdering(1); // Start topological ordering from the first node (node 1)

    printf("The Topological Ordering of the given graph is :\n>>> ");
    
    // Print the topological ordering by popping nodes from the stack
    while (top != 0)
    {
        printf("%d --> ", stack[top--]); // Print and remove the top element from the stack
    }
    
    printf("%d\n", stack[0]); // Print the last element in the stack
    
    return 0;
}