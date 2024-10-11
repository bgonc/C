#include <stdio.h>

int main()
{
    int n;
    int i=3;
    int soma;
    int fib1=1;
    int fib2=2;

    printf("Calculo do valor da funcao Fibonacci:\nIndique N: ");
    scanf("%d", &n);
    
    while(i<=n)
    {
    
    soma=fib1+fib2;
    
    printf("Fib(%d)=%d\n", i, soma);
    
    fib1=fib2;
    fib2=soma;

    i++;
    }   
}