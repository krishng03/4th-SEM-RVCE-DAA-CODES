#include <stdio.h>
#include <stdlib.h>
#define SIZE 512

int count = 0;

// Function to merge two sorted subarrays into one sorted array
void merge(int* arr, int l, int m, int r, int n)
{
    int i = l, j = m + 1, k = l;
    int* temp = (int*)malloc(n * sizeof(int)); // Temporary array to hold merged values

    // Merge the two subarrays into the temporary array
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
        count++; // Count the number of comparisons made during merging
    }

    // Copy any remaining elements from the first subarray
    while (i <= m)
        temp[k++] = arr[i++];

    // Copy any remaining elements from the second subarray
    while (j <= r)
        temp[k++] = arr[j++];

    // Copy the merged elements from the temporary array back to the original array
    for (int a = l; a <= r; a++)
        arr[a] = temp[a];
}

// Recursive function to perform merge sort
void mergesort(int* arr, int l, int r, int n)
{
    if (l < r)
    {
        count++; // Increment the count when the function is called
        int m = (l + r) / 2; // Calculate the midpoint of the array
        // Recursively sort the left and right halves of the array
        mergesort(arr, l, m, n);
        mergesort(arr, m + 1, r, n);
        // Merge the sorted halves to create a single sorted array
        merge(arr, l, m, r, n);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:\n>>> ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int)); // Allocate memory for the array

    printf("Enter the elements of the array:\n>>> ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Call the merge sort function to sort the array
    mergesort(arr, 0, n - 1, n);

    printf("Elements After Sorting:\n>>> ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nNO\tASC\tDESC\tRAND\n");

    // Testing the algorithm on arrays of different sizes
    for (int i = 16; i < 512; i *= 2)
    {
        int* asc = (int*)malloc(i * sizeof(int));
        int* desc = (int*)malloc(i * sizeof(int));
        int* random = (int*)malloc(i * sizeof(int));

        // Initialize arrays with ascending, descending, and random values
        for (int j = 0; j < i; j++)
        {
            asc[j] = j + 1;
            desc[j] = i - j;
            random[j] = rand() % i;
        }

        count = 0; // Reset the comparison count

        // Sort the ascending array and count comparisons
        mergesort(asc, 0, i - 1, i);
        int c1 = count;

        count = 0; // Reset the comparison count

        // Sort the descending array and count comparisons
        mergesort(desc, 0, i - 1, i);
        int c2 = count;

        count = 0; // Reset the comparison count

        // Sort the random array and count comparisons
        mergesort(random, 0, i - 1, i);
        int c3 = count;

        count = 0; // Reset the comparison count

        printf("%d\t%d\t%d\t%d\n", i, c1, c2, c3);
    }

    return 0;
}