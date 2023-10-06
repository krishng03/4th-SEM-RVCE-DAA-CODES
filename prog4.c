#include <stdio.h>
#include <string.h>
#define SIZE 256
int table[SIZE];

void shiftTable(char pattern[])
{
    int i, m = strlen(pattern);
    for(i = 0; i < SIZE; i++)
    {
        table[i] = m;
    }
    for(i = 0; i < m - 1; i++)
    {
        table[pattern[i]] = m - i - 1;
    }
}

int horspool(char pattern[], char text[])
{
    int m = strlen(pattern), n = strlen(text);
    shiftTable(pattern);
    int i = m - 1;
    while(i < n)
    {
        int k = 0; // for counting no. of matching characters
        while(k < m && pattern[m - 1 - k] == text[i - k])
            k++;
        if(k == m)
            return i - m + 1;
        else
            i += table[text[i]];
    }
    return -1;
}

int main()
{
    char pattern[20], text[50];
    printf("Read Text : ");
    scanf("%s", text);
    printf("Read Pattern : ");
    scanf("%s", pattern);
    int idx = horspool(pattern, text);
    if(idx == -1)
        printf("No");
    else
        printf("Yes, at index : %d\n", idx);
    return 0;
}