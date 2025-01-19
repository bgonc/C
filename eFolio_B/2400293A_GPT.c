#include <stdio.h>
#include <stdlib.h>

// Enumeração para definir os tipos de abelhas
typedef enum
{
    FAX, // Faxineiras
    NUT, // Nutrizes
    CON, // Construtoras
    GUA, // Guardiãs
    FOR, // Forrageiras
    ZAN, // Zangões
    RAI  // Rainha
} TipoAbelha;

// Estrutura que representa uma abelha
typedef struct
{
    TipoAbelha tipo;      // Tipo da abelha
    int tempoNascimento;  // Tempo de nascimento em minutos negativos
} Abelha;

// Estrutura que representa a colmeia
typedef struct
{
    Abelha *abelhas;       // Ponteiro para o array de abelhas
    int numeroAbelhas;     // Número total de abelhas na colmeia
} Colmeia;

// Função para inicializar as abelhas na colmeia
void inicializarAbelhas(Colmeia *colmeia, int N)
{
    // Calcula o número de abelhas por dia (de idade)
    int abelhasPorDia = N / 40;

    // Se não houver pelo menos 5 abelhas por dia, a colmeia fica vazia
    if (abelhasPorDia < 5)
    {
        colmeia->numeroAbelhas = 0;
        colmeia->abelhas = NULL;
        return;
    }

    // Calcula o número total de abelhas: operárias, zangões e 1 rainha
    colmeia->numeroAbelhas = abelhasPorDia * 40 + 41;

    // Aloca memória para o array de abelhas
    colmeia->abelhas = malloc(sizeof(Abelha) * colmeia->numeroAbelhas);

    // Índice para acompanhar a inserção de abelhas
    int indiceAbelha = 0;

    // Inicializa as operárias com base nos dias e funções
    for (int dia = 1; dia <= 40; dia++)
    {
        for (int b = 0; b < abelhasPorDia; b++)
        {
            TipoAbelha tipo = b % 5; // Alterna entre os tipos FAX, NUT, CON, GUA, FOR
            colmeia->abelhas[indiceAbelha].tipo = tipo;
            colmeia->abelhas[indiceAbelha].tempoNascimento = -(dia * 1440 - b); // Em minutos negativos
            indiceAbelha++;
        }
    }

    // Inicializa os zangões com idades distribuídas entre 1 e 40 dias
    for (int i = 0; i < 40; i++)
    {
        colmeia->abelhas[indiceAbelha].tipo = ZAN;
        colmeia->abelhas[indiceAbelha].tempoNascimento = -(i + 1) * 1440;
        indiceAbelha++;
    }

    // Inicializa a rainha (idade 0)
    colmeia->abelhas[indiceAbelha].tipo = RAI;
    colmeia->abelhas[indiceAbelha].tempoNascimento = 0;
}

// Função para imprimir o relatório inicial da colmeia
void imprimirRelatorio(Colmeia *colmeia)
{
    int contadorAbelhas[7] = {0}; // Contador para cada tipo de abelha

    // Conta o número de abelhas de cada tipo
    for (int i = 0; i < colmeia->numeroAbelhas; i++)
    {
        if (colmeia->abelhas[i].tipo != -1) // Verifica se a abelha está ativa
        {
            contadorAbelhas[colmeia->abelhas[i].tipo]++;
        }
    }

    // Imprime o cabeçalho do relatório
    printf("Relatorio colmeia:\n");
    printf(" fax nut con gua for zan rai ovo lar pup mel pol nec cri zan rea\n");

    // Imprime o número de abelhas de cada tipo
    for (int i = 0; i < 7; i++)
    {
        if (contadorAbelhas[i] > 0)
            printf("%3d ", contadorAbelhas[i]);
        else
            printf("    ");
    }
    printf("\n");

    // Informações fixas sobre as células (não utilizadas nesta alínea)
    printf("    Favo   0:            celulas vazias:\n");
    printf("                                 usadas:\n");
}

int main()
{
    int nAbelhas, nCelulas, minutos, temporadas;

    // Lê os dados de entrada do utilizador
    scanf("%d", &nAbelhas);
    scanf("%d", &nCelulas);
    scanf("%d", &minutos);
    scanf("%d", &temporadas);

    Colmeia colmeia;

    // Inicializa as abelhas da colmeia
    inicializarAbelhas(&colmeia, nAbelhas);

    // Imprime o relatório inicial
    imprimirRelatorio(&colmeia);

    // Libera a memória alocada para as abelhas
    if (colmeia.abelhas)
        free(colmeia.abelhas);

    return 0;
}
