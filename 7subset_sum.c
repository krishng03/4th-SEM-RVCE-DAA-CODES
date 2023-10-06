#include <stdio.h>
#define SIZE 100

int arr[SIZE], sum, cnt, n;

// Function to find and print subsets that sum to a given target
void subset(int temp[SIZE], int sub, int k)
{
    if (k == n)
    {
        // If the current subset's sum equals the target sum, print it
        if (sum == sub)
        {
            printf("SUBSET %d : \n{ ", cnt++);
            for (int i = 0; i < n; i++)
            {
                if (temp[i] != -1)
                {
                    printf("%d ", temp[i]);
                }
            }
            printf("}\n");
        }
        return;
    }

    // Include the current element in the subset
    temp[k] = arr[k];
    sub += arr[k];
    subset(temp, sub, k + 1);

    // Exclude the current element from the subset
    temp[k] = -1;
    sub -= arr[k];
    subset(temp, sub, k + 1);
}

int main()
{
    int temp[SIZE];
    printf("Read Size :\n>>> ");
    scanf("%d", &n);

    printf("Read Elements :\n>>> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        temp[i] = -1; // Initialize the temporary array for subsets
    }

    printf("Read Sum :\n>>> ");
    scanf("%d", &sum);

    subset(temp, 0, 0); // Call the subset function to find and print subsets with the target sum

    return 0;
}