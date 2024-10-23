#include <stdio.h>

int main()

{
    double n = 1;
    double f = 1;
    int k;
    int i = 1;

    printf("indique K: ");
    scanf("%d", &k);

    while (i <= k)
    {
        f *= i;
        n += 1 / f;

        printf("%d: %.16g\n", i, n);

        i++;
    }
}