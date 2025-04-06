#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conteudos.h"
#include "interacoes.h"

// Permite ao utilizador registar uma interação com um conteúdo
void registarInteracao(Conteudo *lista, int num)
{
    int idx;
    char tipo[20];

    if (num == 0)
    {
        printf("Não existem conteúdos disponíveis.\n");
        return;
    }

    listarConteudos(lista, num);

    printf("Escolha o número do conteúdo: ");
    scanf("%d", &idx);
    getchar(); // limpar o \n do buffer

    if (idx < 1 || idx > num)
    {
        printf("Conteúdo inválido.\n");
        return;
    }

    idx--; // converter para índice do array

    printf("Tipo de interação (Reproduzir, Pausa, Terminar): ");
    fgets(tipo, sizeof(tipo), stdin);
    tipo[strcspn(tipo, "\n")] = 0;

    // Se a interação for "Terminar", aumenta o contador de visualizações
    if (strcmp(tipo, "Terminar") == 0)
    {
        lista[idx].visualizacoes++;
        printf("Visualização registada com sucesso.\n");
    }
    else
    {
        printf("Interação '%s' registada (sem alterar visualizações).\n", tipo);
    }

    // Regista a interação num ficheiro externo (append)
    FILE *f = fopen("interacoes.csv", "a");
    if (f != NULL)
    {
        fprintf(f, "%s,%s\n", lista[idx].titulo, tipo);
        fclose(f);
    }
    else
    {
        printf("Erro ao gravar no ficheiro de interações.\n");
    }
}
