#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int size;
    int i;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    printf("Digite %d numeros: \n", size);

    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Indicou: \n");
    for(i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }

    free (arr);

}