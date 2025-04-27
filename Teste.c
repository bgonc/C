
#include <stdio.h>
// teste de commit

long long int power(int n, int p)
{
    long long int  resultado = 1;
    
    while (p > 0)
	{
	    resultado *= n;
	    p--;
	}
    return resultado;
}

int main()
{
    int num;
    int pow;

    printf("Indique o número:");
    scanf("%d", &num);
    printf("Indique a potência:");
    scanf("%d", &pow);

    printf("%d elevado a %d = %lld\n",num, pow, power(num, pow));

    return 0;
}
// mais um teste
