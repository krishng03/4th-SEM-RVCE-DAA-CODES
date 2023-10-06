#include <stdio.h>

int n, sourceNode, cost[10][10], d[10], v[10]; // Variables for Dijkstra's algorithm

// Function to perform Dijkstra's algorithm for finding shortest paths
void djikstra()
{
    int min, i, j, u;
    v[sourceNode] = 1; // Mark the source node as visited

    for (i = 1; i <= n; i++)
    {
        min = 999; // Initialize the minimum distance to a large value
        // Find the unvisited node with the minimum distance
        for (j = 1; j <= n; j++)
        {
            if (v[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        v[u] = 1; // Mark the selected node as visited

        // Update distances to adjacent nodes if a shorter path is found
        for (j = 1; j <= n; j++)
        {
            if (v[j] == 0 && d[j] > d[u] + cost[u][j])
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]); // Read the adjacency matrix representing the graph
        }
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = cost[sourceNode][i]; // Initialize distances with the cost from the source node
        v[i] = 0; // Mark all nodes as unvisited
    }

    djikstra(); // Call Dijkstra's algorithm to find shortest paths

    // Print the shortest distances from the source node to each node
    for (int i = 1; i <= n; i++)
        printf("%d --> %d = %d\n", sourceNode, i, d[i]);

    return 0;
}