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

/* Verifica se a sequência é válida */
int verificar_sequencia(int k, int vetor[], int tamanho)
{
    int soma = 0;
    unsigned long long produto = 1; // Usar tipo maior para evitar overflow
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
        produto *= vetor[i];
        if (produto > k)
        { // Evita overflow
            produto = k + 1;
        }
    }
    return soma <= k && produto >= k;
}

/* Verifica se a sequência é uma sequência de vitória */
int verificar_vitoria(int k, int vetor[], int tamanho)
{
    int soma_diferencas = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            soma_diferencas += abs(vetor[i] - vetor[j]);
        }
    }
    return soma_diferencas == k;
}

/* Imprime a sequência atual */
void imprimir_sequencia(int vetor[], int tamanho, char jogador, int ultima)
{
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    if (!ultima)
    {
        printf("[Joga %c]\n", jogador);
    }
    else
    {
        printf("\n");
    }
}

/* Processa uma jogada */
/* Processa uma jogada */
int processar_jogada(int vetor[], int *tamanho, int indice, int valor)
{
    if (indice < 0)
    {
        indice = 0; // Trata índices negativos como 0
    }
    if (indice >= *tamanho)
    {
        if (valor > 0)
        {
            vetor[*tamanho] = valor;
            (*tamanho)++;
        }
        else if (valor < 0)
        {
            vetor[*tamanho] = -valor;
            (*tamanho)++;
        }
        // Allow valor == 0 when indice >= *tamanho (if intended)
    }
    else if (valor == 0)
    {
        for (int i = indice; i < *tamanho - 1; i++)
        {
            vetor[i] = vetor[i + 1];
        }
        (*tamanho)--;
    }
    else if (valor < 0)
    {
        for (int i = *tamanho; i > indice; i--)
        {
            vetor[i] = vetor[i - 1];
        }
        vetor[indice] = -valor;
        (*tamanho)++;
    }
    else
    {
        vetor[indice] = valor;
    }
    return 1; // Always return 1 as in Code C
}


/* Lógica do jogador artificial */
void jogador_artificial(int vetor[], int *tamanho, int k, int *indice, int *valor)
{
    int tamanho_vetor = *tamanho;
    int max_possible_moves = 10000;
    struct Move
    {
        int index;
        int value;
    };
    struct Move moves[10000];
    int move_count = 0;

    // Criar lista de índices ordenados pelo valor decrescente
    int indices[100];
    for (int i = 0; i < tamanho_vetor; i++)
    {
        indices[i] = i;
    }

    // Ordenar os índices pelo valor decrescente dos elementos em 'vetor'
    for (int i = 0; i < tamanho_vetor - 1; i++)
    {
        for (int j = i + 1; j < tamanho_vetor; j++)
        {
            if (vetor[indices[i]] < vetor[indices[j]] ||
                (vetor[indices[i]] == vetor[indices[j]] && indices[i] > indices[j]))
            {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Tentar os índices em ordem de valor decrescente
    for (int idx_i = 0; idx_i < tamanho_vetor; idx_i++)
    {
        int I = indices[idx_i];
        int V = vetor[I];

        move_count = 0;

        int soma = 0;
        for (int j = 0; j < tamanho_vetor; j++)
        {
            soma += vetor[j];
        }

        // Considerar remover (valor=0) ou reduzir o número (valor=1,...,V-1)
        if (move_count < max_possible_moves)
        {
            moves[move_count].index = I;
            moves[move_count].value = 0;
            move_count++;
        }

        for (int v = 1; v < V; v++)
        {
            if (move_count < max_possible_moves)
            {
                moves[move_count].index = I;
                moves[move_count].value = v;
                move_count++;
            }
            else
            {
                break;
            }
        }

        // Se a soma for menor que K, considerar aumentar o número e adicionar novo número
        if (soma < k)
        {
            int max_increase = k - soma;
            // Aumentar o número
            for (int v = V + 1; v <= V + max_increase; v++)
            {
                if (move_count < max_possible_moves)
                {
                    moves[move_count].index = I;
                    moves[move_count].value = v;
                    move_count++;
                }
                else
                {
                    break;
                }
            }

            // Adicionar novo número
            for (int v = 1; v <= (k - soma); v++)
            {
                if (move_count < max_possible_moves)
                {
                    moves[move_count].index = I;  // adiciona no índice I
                    moves[move_count].value = -v; // valor negativo indica adição
                    move_count++;
                }
                else
                {
                    break;
                }
            }
        }

        // Procurar jogada que leva à vitória
        for (int m = 0; m < move_count; m++)
        {
            // Aplicar a jogada hipotética
            int temp_vetor[100];
            int temp_tamanho = tamanho_vetor;

            for (int i = 0; i < tamanho_vetor; i++)
            {
                temp_vetor[i] = vetor[i];
            }

            int idx = moves[m].index;
            int val = moves[m].value;

            if (!processar_jogada(temp_vetor, &temp_tamanho, idx, val))
            {
                continue; // Jogada inválida
            }

            if (!verificar_sequencia(k, temp_vetor, temp_tamanho))
            {
                continue; // Sequência inválida após a jogada
            }

            if (verificar_vitoria(k, temp_vetor, temp_tamanho))
            {
                // Jogada que leva à vitória encontrada
                *indice = moves[m].index;
                *valor = moves[m].value;
                return;
            }
        }

        // Se não houver jogada vencedora, escolher a jogada válida com menor tamanho
        int min_size = 100;
        int best_move = -1;

        for (int m = 0; m < move_count; m++)
        {
            // Aplicar a jogada hipotética
            int temp_vetor[100];
            int temp_tamanho = tamanho_vetor;

            for (int i = 0; i < tamanho_vetor; i++)
            {
                temp_vetor[i] = vetor[i];
            }

            int idx = moves[m].index;
            int val = moves[m].value;

            if (!processar_jogada(temp_vetor, &temp_tamanho, idx, val))
            {
                continue; // Jogada inválida
            }

            if (!verificar_sequencia(k, temp_vetor, temp_tamanho))
            {
                continue; // Sequência inválida após a jogada
            }

            if (temp_tamanho < min_size)
            {
                min_size = temp_tamanho;
                best_move = m;
            }
        }

        if (best_move != -1)
        {
            *indice = moves[best_move].index;
            *valor = moves[best_move].value;
            return;
        }

        // Se nenhuma jogada válida foi encontrada, tentar o próximo índice
    }

    // Se nenhuma jogada válida foi encontrada em nenhum índice
    *indice = -1;
    *valor = -1;
}

/* Função principal */
int main()
{
    int k, vetor[100], tamanho = 2, jogadas = 0, max_jogadas;
    char jogador = 'A';

    printf("Indique K:\n");
    scanf("%d", &k);

    if (!validar_K(k))
    {
        return 1;
    }

    vetor[0] = k / 2;
    vetor[1] = k / 2;
    if (k % 2 != 0)
    {
        vetor[1] += 1;
    }
    max_jogadas = k;

    imprimir_sequencia(vetor, tamanho, jogador, 0);

    int inseriu_removeu = 0;
    char ultimo_jogador = jogador;

    while (jogadas < max_jogadas)
    {
        int indice, valor;

        if (jogador != ultimo_jogador)
        {
            inseriu_removeu = 0;
            ultimo_jogador = jogador;
        }

        printf("Jogada (indice valor):\n");
        scanf("%d %d", &indice, &valor);

        if (indice == -2 && valor == -2)
        {
            jogador_artificial(vetor, &tamanho, k, &indice, &valor);
            if (indice == -1)
            {
                imprimir_sequencia(vetor, tamanho, jogador, 1);
                printf("Jogador %c perdeu.\n", jogador);
                return 0;
            }
            else
            {
                printf("Jogada artificial: %d %d\n", indice, valor);
            }
        }

        if (!processar_jogada(vetor, &tamanho, indice, valor))
        {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogador %c perdeu.\n", jogador);
            return 0;
        }

        /* Verificar sequência inválida */
        if (!verificar_sequencia(k, vetor, tamanho))
        {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogador %c perdeu.\n", jogador);
            return 0;
        }

        /* Verificar sequência de vitória */
        if (verificar_vitoria(k, vetor, tamanho))
        {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogador %c ganhou.\n", jogador);
            return 0;
        }

        // Incrementar o número de jogadas
        jogadas++;

        // Verificar se atingiu o número máximo de jogadas
        if (jogadas >= max_jogadas)
        {
            break; // Não imprime a sequência com [Joga X]
        }

        // Verificar se foi inserido ou removido um número
        if (valor == 0 || valor < 0)
        {
            if (inseriu_removeu == 0)
            {
                // Primeira inserção ou remoção
                inseriu_removeu = 1;
                // A vez continua com o mesmo jogador
            }
            else
            {
                // Segunda inserção ou remoção, passa a vez
                inseriu_removeu = 0;
                jogador = (jogador == 'A') ? 'B' : 'A';
            }
        }
        else
        {
            // Modificou valor, passa a vez
            inseriu_removeu = 0;
            jogador = (jogador == 'A') ? 'B' : 'A';
        }

        imprimir_sequencia(vetor, tamanho, jogador, 0);
    }

    // Imprimir sequência final sem o indicador de jogador
    imprimir_sequencia(vetor, tamanho, jogador, 1);
    printf("Empate.\n");
    return 0;
}
