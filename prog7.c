#include <stdio.h>
#define SIZE 100
int arr[SIZE], sum, cnt, n;

void subset(int temp[SIZE], int sub, int k)
{
    if(k == n)
    {
        if(sum == sub)
        {
            printf("SUBSET %d : \n{ ", cnt++);
            for(int i = 0; i < n; i++)
            {
                if(temp[i] != -1)
                {
                    printf("%d ", temp[i]);
                }
            }
            printf("}\n");
        }
        return ;
    }
    temp[k] = arr[k];
    sub += arr[k];
    subset(temp, sub, k+1);
    temp[k] = -1;
    sub -= arr[k];
    subset(temp, sub, k+1);

}

int main()
{
    int temp[SIZE];
    printf("Read Size :\n>>> ");
    scanf("%d", &n);
    printf("Read Elements :\n>>> ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        temp[i] = -1;
    }
    printf("Read Sum :\n>>> ");
    scanf("%d", &sum);
    subset(temp, 0, 0);
    return 0;
}