#include <stdio.h>

int main()
{
    int num;
    int pow;
    

    printf("Indique o número:");
    scanf("%d", &num);
    printf("Indique a potência:");
    scanf("%d", &pow);

    long long int resultado = 1;
    int tempPow = pow;

    while (pow > 0)
    {
        
        resultado *= num;
        pow--;
    }

    printf("%d elevado a %d = %lld\n", num, tempPow, resultado);

    return 0;
}   