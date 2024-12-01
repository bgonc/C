#include <stdio.h>
#include <stdlib.h>

/* Valida se K está entre 2 e 100 */
int validar_K(int k)
{
    if (k < 2 || k > 100)
    {
        printf("K tem de ser entre 2 e 100.\n");
        return 0;
    }
    return 1;
}

/* Verifica a sequência fornecida */
void verificar_sequencia(int k, int vetor[], int tamanho)
{
    int soma = 0, produto = 1, soma_diferencas = 0;

    /* Calcula a soma e o produto da sequência */
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
        produto *= vetor[i];
    }

    /* Verifica se a sequência é inválida */
    if (soma > k || produto < k)
    {
        printf("Sequencia invalida\n");
        return;
    }

    /* Calcula a soma das diferenças absolutas entre todos os pares */
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            soma_diferencas += abs(vetor[i] - vetor[j]);
        }
    }

    /* Determina o tipo de sequência */
    if (soma_diferencas == k)
    {
        printf("Sequencia vitoria\n");
    }
    else
    {
        printf("Sequencia valida\n");
    }
}

int main()
{
    int k, vetor[100], tamanho = 0, num = 1; // Inicializa num com um valor diferente de 0

    printf("Indique K: ");
    scanf("%d", &k);

    if (validar_K(k))
    {
        printf("Indique uma sequencia de numeros inteiros positivos, terminando com 0: ");
        while (num != 0) // Loop até que o utilizador insira 0
        {
            scanf("%d", &num);

            if (num != 0 && tamanho < 100)
            {
                vetor[tamanho++] = num;
            }
        }

        /* Verificar a sequência fornecida */
        verificar_sequencia(k, vetor, tamanho);
    }
}