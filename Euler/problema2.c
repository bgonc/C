#include <stdio.h>

void main()
{
    int K;
    int soma;
    int i = 1;
    int fib1 = 1;
    int fib2 = 2;


    scanf("%d", &K);

    while (i < K)
    {
        soma = fib1 + fib2;
        printf("%d\n", soma);

        fib1 = fib2;
        fib2 = soma;

        i++;

    }
    





    //printf("%d",soma);
}