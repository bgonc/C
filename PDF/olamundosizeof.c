#include <stdio.h>

int main()

{
    printf("Olá Mundo!");
    printf("\nsizeof(char): %zu", sizeof(char));
    printf("\nsizeof(short): %zu", sizeof(short));
    printf("\nsizeof(int): %zu", sizeof(int));
    printf("\nsizeof(long): %zu", sizeof(long));
    printf("\nsizeof(long long): %zu", sizeof(long long));
    printf("\nsizeof(float): %zu", sizeof(float));
    printf("\nsizeof(double): %zu", sizeof(double));
    printf("\nsizeof(double long): %zu", sizeof(long double));

    printf("\nO total é %zu", sizeof(short)+sizeof(int)+sizeof(long)+sizeof(long long)+sizeof(float)+sizeof(double)+sizeof(long double));
}