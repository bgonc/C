#include <stdio.h>

// TODO: Define the function to double each array element using a pointer
void doubleArray(int *arr, int *size)
{
    // Loop through the array using a pointer
    for (int i = 0; i < *size; i++)
    {
        // TODO: Double each element using a pointer
        *(arr + i) *= 2;
    }
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Before: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // TODO: Call the function to double the array elements
    doubleArray(numbers, &size);

    printf("After: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
