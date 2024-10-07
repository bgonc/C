#include <stdio.h>

int main()
{
	printf("Olá Mundo!\n\n");
	printf("sizeof(char): %d\n", sizeof(char));
	printf("sizeof(short): %d\n", sizeof(short));
	printf("sizeof(int): %d\n", sizeof(int));
	printf("sizeof(long): %d\n", sizeof(long));
	printf("sizeof(long long): %d\n", sizeof(long long));
	printf("sizeof(float): %d\n", sizeof(float));
	printf("sizeof(double): %d\n", sizeof(double));
	printf("sizeof(long double): %d\n\n", sizeof(long double)); 

/* calcular a soma dos tamanhos */
	
	printf("O total dos tamanhos é %d\n", sizeof(char) + sizeof(short) + sizeof(int) + sizeof(long) + sizeof(long long) + sizeof(float) + sizeof(double) + sizeof(long double));
	
}
