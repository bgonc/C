#include <stdio.h>

unsigned int randaux()
{
    static long seed = 1;
    seed = seed * 214013L + 2531011L;
    return ((seed >> 16) & 0x7fff);
}

void PrintInts(int v[], int n, const char* sep)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", v[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("%s", n);
}

void Sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Compare with all subsequent elements
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                // Swap elements if they are in reverse order
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main()
{
    int v[1000], i, n;

    // Read the maximum random number
    scanf("%d", &n);
    n++;

    // Fill the array with random numbers from 0 to N
    for (i = 0; i < 1000; i++)
        v[i] = randaux() % n;

    // Print the first 10 numbers before sorting
    PrintInts(v, 10, "\n");

    // Sort the array
    Sort(v, 1000);

    // Print the first 10 numbers after sorting
    PrintInts(v, 10, "\n");

    return 0;
}
