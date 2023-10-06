#include <stdio.h>
#include <stdlib.h>
#define SIZE 512
int count = 0;
void merge(int* arr, int l, int m, int r, int n)
{
    int i = l, j = m+1, k = l;
    int* temp = (int* )malloc(n*sizeof(int));
    while(i <= m && j <= r)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
            count++;
        }
        else
        {
            temp[k++] = arr[j++];
            count++;
        }
    }
    while(i <= m)
    {
        temp[k++] = arr[i++];
        // count++;
    }
    while(j <= r)
    {
        temp[k++] = arr[j++];
        // count++;
    }
    for(int a = l; a <= r; a++)
        arr[a] = temp[a];
}

void mergesort(int* arr, int l, int r, int n)
{
    if(l < r)
    {
        int m = (l + r)/2;
        mergesort(arr, l, m, n);
        mergesort(arr, m+1, r, n);
        merge(arr, l, m, r, n);
    }
}

int main()
{
    int n;
    int* arr = (int *)malloc(n*sizeof(int));
    printf("Read Size :\n>>> ");
    scanf("%d", &n);
    printf("Read Elements :\n>>> ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergesort(arr, 0, n-1, n);
    printf("Elements After Sorting :\n>>> ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("NO\tASC\tDESC\tRAND\n");
    for(int i = 16; i < 512; i*=2)
    {
        int* asc = (int *)malloc(i*sizeof(int));
        int* desc = (int *)malloc(i*sizeof(int));
        int* random = (int *)malloc(i*sizeof(int));
        for(int j = 0; j < i; j++)
        {
            asc[j] = j+1;
            desc[j] = i - j;
            random[j] = rand()%i;
        }
        count = 0;
        mergesort(asc, 0, i-1, i);
        int c1 = count;
        count = 0;
        mergesort(desc, 0, i-1, i);
        int c2 = count;
        count = 0;
        mergesort(random, 0, i-1, i);
        int c3 = count;
        count = 0;
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, c3);
    }

    return 0;
}