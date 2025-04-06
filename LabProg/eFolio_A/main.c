#include <stdio.h>
#include <stdlib.h>
#include "conteudos.h"
#include "interacoes.h"

#define FICHEIRO_CSV "conteudos.csv"

int main()
{
    Conteudo *lista = NULL;
    int numConteudos = 0;
    int opcao;

    // Leitura inicial do ficheiro CSV
    lista = lerConteudosCSV(FICHEIRO_CSV, &numConteudos);

    do
    {
        printf("\n=== STREAMFLIX ===\n");
        printf("1 - Listar conteúdos\n");
        printf("2 - Adicionar conteúdo\n");
        printf("3 - Editar conteúdo\n");
        printf("4 - Remover conteúdo\n");
        printf("5 - Pesquisar por título\n");
        printf("6 - Registar interação\n");
        printf("7 - Pesquisar por categoria\n");
        printf("8 - Pesquisar por classificação etária\n");
        printf("9 - Ver conteúdo mais visualizado\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar o \n do buffer

        switch (opcao)
        {
        case 1:
            listarConteudos(lista, numConteudos);
            break;
        case 2:
            lista = adicionarConteudo(lista, &numConteudos);
            break;
        case 3:
            editarConteudo(lista, numConteudos);
            break;
        case 4:
            lista = removerConteudo(lista, &numConteudos);
            break;
        case 5:
            pesquisarPorTitulo(lista, numConteudos);
            break;
        case 6:
            registarInteracao(lista, numConteudos);
            break;
        case 7:
            pesquisarPorCategoria(lista, numConteudos);
            break;
        case 8:
            pesquisarPorClassEtaria(lista, numConteudos);
            break;
        case 9:
            mostrarMaisVisualizado(lista, numConteudos);
            break;
        case 0:
            printf("A guardar dados e a sair...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    // Gravação final dos conteúdos no ficheiro CSV
    gravarConteudosCSV(FICHEIRO_CSV, lista, numConteudos);

    // Libertar memória alocada dinamicamente
    free(lista);

    return 0;
}