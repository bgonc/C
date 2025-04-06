#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conteudos.h"

// Lê os conteúdos do ficheiro CSV e guarda na memória
void lerConteudosCSV(const char *nomeFicheiro, Conteudo **lista, int *num)
{
    FILE *f = fopen(nomeFicheiro, "r");
    if (!f)
        return;

    Conteudo temp;
    char linha[256];
    *num = 0;
    *lista = NULL;

    while (fgets(linha, sizeof(linha), f))
    {
        // Extrai os dados de uma linha CSV
        sscanf(linha, "%[^,],%[^,],%d,%d,%d\n",
               temp.titulo, temp.categoria,
               &temp.duracao, &temp.classificacaoEtaria,
               &temp.visualizacoes);

        // Redimensiona a memória e adiciona o novo conteúdo
        *lista = realloc(*lista, (*num + 1) * sizeof(Conteudo));
        (*lista)[*num] = temp;
        (*num)++;
    }
    fclose(f);
}

// Guarda os conteúdos no ficheiro CSV
void gravarConteudosCSV(const char *nomeFicheiro, Conteudo *lista, int num)
{
    FILE *f = fopen(nomeFicheiro, "w");
    if (!f)
        return;

    for (int i = 0; i < num; i++)
    {
        fprintf(f, "%s,%s,%d,%d,%d\n",
                lista[i].titulo, lista[i].categoria,
                lista[i].duracao, lista[i].classificacaoEtaria,
                lista[i].visualizacoes);
    }

    fclose(f);
}

// Mostra todos os conteúdos disponíveis no ecrã
void listarConteudos(Conteudo *lista, int num)
{
    printf("\n--- Lista de Conteudos ---\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d. %s | %s | %d min | %d+ | %d views\n",
               i + 1,
               lista[i].titulo,
               lista[i].categoria,
               lista[i].duracao,
               lista[i].classificacaoEtaria,
               lista[i].visualizacoes);
    }
}

// Adiciona um novo conteúdo à lista
void adicionarConteudo(Conteudo **lista, int *num)
{
    Conteudo novo;

    // Leitura dos dados do novo conteúdo
    printf("Titulo: ");
    fgets(novo.titulo, MAX_TITULO, stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = 0;

    printf("Categoria: ");
    fgets(novo.categoria, MAX_CATEGORIA, stdin);
    novo.categoria[strcspn(novo.categoria, "\n")] = 0;

    printf("Duracao (min): ");
    scanf("%d", &novo.duracao);
    getchar();

    printf("Classificacao etaria: ");
    scanf("%d", &novo.classificacaoEtaria);
    getchar();

    novo.visualizacoes = 0;

    // Redimensiona e adiciona
    *lista = realloc(*lista, (*num + 1) * sizeof(Conteudo));
    (*lista)[*num] = novo;
    (*num)++;

    printf("Conteudo adicionado!\n");
}

// Edita um conteúdo existente da lista
void editarConteudo(Conteudo *lista, int num)
{
    int idx;

    printf("Indice do conteudo a editar (1 a %d): ", num);
    scanf("%d", &idx);
    getchar();

    if (idx < 1 || idx > num)
        return;
    idx--; // Corrige índice para array (começa em 0)

    // Leitura dos novos dados
    printf("Novo titulo: ");
    fgets(lista[idx].titulo, MAX_TITULO, stdin);
    lista[idx].titulo[strcspn(lista[idx].titulo, "\n")] = 0;

    printf("Nova categoria: ");
    fgets(lista[idx].categoria, MAX_CATEGORIA, stdin);
    lista[idx].categoria[strcspn(lista[idx].categoria, "\n")] = 0;

    printf("Nova duracao: ");
    scanf("%d", &lista[idx].duracao);
    getchar();

    printf("Nova classificacao: ");
    scanf("%d", &lista[idx].classificacaoEtaria);
    getchar();

    printf("Conteudo atualizado!\n");
}

// Remove um conteúdo da lista
void removerConteudo(Conteudo **lista, int *num)
{
    int idx;

    printf("Indice do conteudo a remover (1 a %d): ", *num);
    scanf("%d", &idx);
    getchar();

    if (idx < 1 || idx > *num)
        return;
    idx--;

    // Desloca os elementos após o removido
    for (int i = idx; i < *num - 1; i++)
    {
        (*lista)[i] = (*lista)[i + 1];
    }

    (*num)--;

    // Reduz a memória alocada
    *lista = realloc(*lista, (*num) * sizeof(Conteudo));

    printf("Conteudo removido!\n");
}

// Pesquisa por título parcial no array de conteúdos
void pesquisarConteudo(Conteudo *lista, int num)
{
    char termo[MAX_TITULO];

    printf("Termo de pesquisa: ");
    fgets(termo, MAX_TITULO, stdin);
    termo[strcspn(termo, "\n")] = 0;

    printf("\n--- Resultados da Pesquisa ---\n");

    for (int i = 0; i < num; i++)
    {
        if (strstr(lista[i].titulo, termo) != NULL)
        {
            printf("%d. %s | %s | %d min | %d+ | %d views\n",
                   i + 1,
                   lista[i].titulo,
                   lista[i].categoria,
                   lista[i].duracao,
                   lista[i].classificacaoEtaria,
                   lista[i].visualizacoes);
        }
    }
}
