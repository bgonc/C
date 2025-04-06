#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conteudos.h"
#include "interacoes.h"

int main()
{
    Conteudo *conteudos = NULL; // Ponteiro para o array dinâmico de conteúdos
    int numConteudos = 0;       // Número atual de conteúdos carregados

    // Carrega os conteúdos a partir do ficheiro CSV
    lerConteudosCSV("conteudos.csv", &conteudos, &numConteudos);

    int opcao;
    do
    {
        // Menu principal apresentado ao utilizador
        printf("\n=== MENU STREAMFLIX ===\n");
        printf("1 - Listar conteudos\n");
        printf("2 - Adicionar conteudo\n");
        printf("3 - Editar conteudo\n");
        printf("4 - Remover conteudo\n");
        printf("5 - Pesquisar por titulo\n");
        printf("6 - Registar interação (reproduzir/pausa/terminar)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o \n do buffer após leitura do número

        // Ação correspondente à opção escolhida
        switch (opcao)
        {
        case 1:
            listarConteudos(conteudos, numConteudos);
            break;
        case 2:
            adicionarConteudo(&conteudos, &numConteudos);
            break;
        case 3:
            editarConteudo(conteudos, numConteudos);
            break;
        case 4:
            removerConteudo(&conteudos, &numConteudos);
            break;
        case 5:
            pesquisarConteudo(conteudos, numConteudos);
            break;
        case 6:
            registarInteracao(conteudos, numConteudos);
            break;
        case 0:
            printf("A sair...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Guarda os dados atualizados no ficheiro antes de sair
    gravarConteudosCSV("conteudos.csv", conteudos, numConteudos);

    free(conteudos); // Liberta a memória alocada dinamicamente

    return 0;
}
