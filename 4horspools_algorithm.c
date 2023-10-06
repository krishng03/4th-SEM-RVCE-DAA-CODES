#include <stdio.h>
#include <string.h>
#define SIZE 256

int table[SIZE]; // Shift table for Horspool's algorithm

// Function to generate the shift table for Horspool's algorithm
void shiftTable(char pattern[])
{
    int i, m = strlen(pattern);

    // Initialize the shift table with the length of the pattern
    for (i = 0; i < SIZE; i++)
    {
        table[i] = m;
    }

    // Calculate the shift values for each character in the pattern
    for (i = 0; i < m - 1; i++)
    {
        table[pattern[i]] = m - i - 1;
    }
}

// Function to perform string matching using Horspool's algorithm
int horspool(char pattern[], char text[])
{
    int m = strlen(pattern), n = strlen(text);
    shiftTable(pattern); // Generate the shift table
    int i = m - 1;

    while (i < n)
    {
        int k = 0;

        // Compare characters from right to left in the pattern and text
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1; // Pattern found at this index in the text
        else
            i += table[text[i]]; // Shift the index based on the character in the text
    }

    return -1; // Pattern not found in the text
}

int main()
{
    char pattern[20], text[50];

    printf("Read Text : ");
    scanf("%s", text);
    printf("Read Pattern : ");
    scanf("%s", pattern);

    int idx = horspool(pattern, text); // Call Horspool's algorithm for string matching

    if (idx == -1)
        printf("Pattern not found in the text.");
    else
        printf("Pattern found at index : %d\n", idx);

    return 0;
}