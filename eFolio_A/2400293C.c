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
int verificar_sequencia(int k, int vetor[], int tamanho)
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
        return 0; // Sequência inválida
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
        return 2; // Sequência de vitória
    }
    return 1; // Sequência válida
}

/* Gera a sequência inicial com base em K */
void gerar_sequencia_inicial(int k, int sequencia[], int *tamanho)
{
    sequencia[0] = k / 2;
    sequencia[1] = k / 2;
    *tamanho = 2;
}

/* Imprime a sequência e o jogador na mesma linha */
void imprimir_sequencia_e_jogador(int sequencia[], int tamanho, char jogador)
{
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", sequencia[i]);
    }
    printf("[Joga %c]\n", jogador);
}

/* Efetua a jogada de um jogador */
int efetuar_jogada(int sequencia[], int *tamanho, int indice, int valor, int *manter_jogada)
{
    if (indice >= *tamanho) // Adicionar no final
    {
        sequencia[*tamanho] = valor;
        (*tamanho)++;
        *manter_jogada = 0; // Não mantém a jogada
    }
    else if (valor == 0) // Remover o número
    {
        for (int i = indice; i < *tamanho - 1; i++)
        {
            sequencia[i] = sequencia[i + 1];
        }
        (*tamanho)--;
        (*manter_jogada)++;
    }
    else if (valor < 0) // Inserir -valor
    {
        for (int i = *tamanho; i > indice; i--)
        {
            sequencia[i] = sequencia[i - 1];
        }
        sequencia[indice] = -valor;
        (*tamanho)++;
        (*manter_jogada)++;
    }
    else // Substituir valor
    {
        sequencia[indice] = valor;
        *manter_jogada = 0; // Não mantém a jogada
    }

    return 1; // Jogada válida
}

int main()
{
    int k, sequencia[100], tamanho, jogadas = 0;
    char jogador = 'A';
    int manter_jogada = 0;

    printf("Indique K: ");
    scanf("%d", &k);

    if (validar_K(k))
    {
        // Gerar sequência inicial
        gerar_sequencia_inicial(k, sequencia, &tamanho);

        // Imprimir sequência inicial e jogador
        imprimir_sequencia_e_jogador(sequencia, tamanho, jogador);

        // Jogo continua até K jogadas
        while (jogadas < k)
        {
            int indice, valor;

            printf("Jogada (indice valor): ");
            scanf("%d %d", &indice, &valor);

            // Efetuar a jogada
            if (!efetuar_jogada(sequencia, &tamanho, indice, valor, &manter_jogada))
            {
                printf("Jogador %c perdeu.\n", jogador);
                return 0;
            }

            // Verificar validade da sequência
            int resultado = verificar_sequencia(k, sequencia, tamanho);

            if (resultado == 0)
            {
                printf("Jogador %c perdeu.\n", jogador);
                return 0;
            }

            if (resultado == 2)
            {
                printf("Jogador %c venceu.\n", jogador);
                return 0;
            }

            // Imprimir sequência após a jogada
            imprimir_sequencia_e_jogador(sequencia, tamanho, jogador);

            // Lógica de troca de jogador
            if (manter_jogada >= 2 || (valor > 0 && indice >= tamanho - 1))
            {
                jogador = (jogador == 'A') ? 'B' : 'A';
                manter_jogada = 0; // Reset ao contador
            }

            jogadas++;
        }

        // Se chegar a K jogadas sem vitória
        printf("Empate.\n");
    }

    return 0;
}
