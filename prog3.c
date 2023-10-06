#include <stdio.h>
#define SIZE 100

void presort(int arr[SIZE], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1, v = arr[i];
        while(j >= 0 && arr[j]>v)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
    }
}

int main()
{
    int n, arr[SIZE];
    printf("Read Size :\n>>> ");
    scanf("%d", &n);
    printf("Read Elements :\n>>> ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    presort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i+1] == arr[i])
        {
            printf("Elements are not unique!");
            return 0;
        }
    }
    printf("Elements are Unique!");
    return 0;
}