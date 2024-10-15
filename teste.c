#include <stdio.h>

int main()

{
    int n;
    int i=1;

    printf("Funcao que verifica se um numero N e' primo\nIndique N:\n");
    scanf("%d", n);

    while(i<=n)
    {
        n-=i;

        printf("%d", i);

        i++;

    }

}