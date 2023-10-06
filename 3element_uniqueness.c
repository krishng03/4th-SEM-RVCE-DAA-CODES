#include <stdio.h>
#define SIZE 100

// Function to perform a presort (insertion sort) on an array
void presort(int arr[SIZE], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1; // Initialize the index of the previous element
        int v = arr[i]; // Store the current element in a temporary variable

        // Move elements greater than 'v' one position ahead of their current position
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = v; // Insert 'v' at the correct sorted position in the array
    }
}

int main()
{
    int n, arr[SIZE];
    printf("Read Size :\n>>> ");
    scanf("%d", &n);

    printf("Read Elements :\n>>> ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    presort(arr, n); // Sort the array using presort (insertion sort)

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Check if the elements in the sorted array are unique
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] == arr[i])
        {
            printf("\nElements are not unique!");
            return 0;
        }
    }

    printf("Elements are Unique!");
    return 0;
}