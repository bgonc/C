#include <stdio.h>

#define COUNT 5

int main() {

    int values[COUNT] = {5, 10, 15, 20, 25};
    int totalSum = 0;

    float averageValue;

    for (int i = 0; i < COUNT; i++) {
        totalSum += values[i];
    }
    printf("Sum: %d\n", totalSum);

    averageValue = (float)totalSum / COUNT;

    printf("Average: %.2f\n", averageValue);

    return 0;
}
