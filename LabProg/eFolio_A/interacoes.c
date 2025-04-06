#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interacoes.h"
#include "conteudos.h"

// Permite registar uma interação: reproduzir, pausa ou terminar.
// Se for 'terminar', o número de visualizações é incrementado.
void registarInteracao(Conteudo *lista, int num)
{
    int idx;
    char tipo[20];

    printf("\n--- Registar Interação ---\n");

    // Mostra os conteúdos disponíveis
    for (int i = 0; i < num; i++)
    {
        printf("%d. %s\n", i + 1, lista[i].titulo);
    }

    // Escolha do conteúdo
    printf("Escolha o número do conteúdo (1 a %d): ", num);
    scanf("%d", &idx);
    getchar();

    if (idx < 1 || idx > num)
    {
        printf("Índice inválido.\n");
        return;
    }

    idx--; // Ajuste do índice

    // Tipo de interação a registar
    printf("Tipo de interação (reproduzir/pausa/terminar): ");
    fgets(tipo, sizeof(tipo), stdin);
    tipo[strcspn(tipo, "\n")] = 0;

    if (strcmp(tipo, "terminar") == 0)
    {
        lista[idx].visualizacoes++;
        printf("Visualização registada.\n");
    }
    else if (strcmp(tipo, "reproduzir") == 0 || strcmp(tipo, "pausa") == 0)
    {
        printf("Interação '%s' registada.\n", tipo);
    }
    else
    {
        printf("Tipo de interação inválido.\n");
    }
}
