#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDADE 57600 // 40 dias em minutos
#define POLEN_POR_REFEICAO 4
#define MEL_POR_REFEICAO 10

// Estrutura para armazenar uma abelha
typedef struct {
    int tipo; // 0=fax, 1=nut, 2=con, 3=gua, 4=forr, 5=zan, 6=rai
    int idade;
    int ultimaRefeicao;
    int viva; // 1 = viva, 0 = morta
} Abelha;

// Estrutura para células de um favo
typedef struct {
    char tipo[4]; // Tipo de célula: "mel", "pol", "nec", "cri", "zan", "rea"
    int quantidade; // Quantidade disponível (em mg) ou estado (ocupada/vazia)
} Celula;

// Estrutura para um favo
typedef struct {
    int id;
    Celula *celulas; // Array dinâmico de células
    int totalCelulas;
} Favo;

// Estrutura para a colmeia
typedef struct {
    Abelha *abelhas; // Array dinâmico de abelhas
    int totalAbelhas;
    Favo *favos; // Array dinâmico de favos
    int totalFavos;
    int totalMel;
    int totalPol;
} Colmeia;

// Função para inicializar a colmeia
void inicializarColmeiaDinamica(Colmeia *colmeia, int nAbelhas, int nCelulas) {
    colmeia->totalAbelhas = nAbelhas;
    colmeia->abelhas = (Abelha *)malloc(nAbelhas * sizeof(Abelha));

    // Inicializar abelhas
    for (int i = 0; i < nAbelhas; i++) {
        colmeia->abelhas[i].tipo = i % 6; // Distribuição inicial
        colmeia->abelhas[i].idade = i * 1440 / nAbelhas; // Idade inicial espaçada
        colmeia->abelhas[i].ultimaRefeicao = 0; // Alimentadas inicialmente
        colmeia->abelhas[i].viva = 1; // Todas começam vivas
    }

    // Inicializar favos e células
    colmeia->totalFavos = (nCelulas + 2999) / 3000; // Número de favos
    colmeia->favos = (Favo *)malloc(colmeia->totalFavos * sizeof(Favo));
    int celulasPorFavo = nCelulas / colmeia->totalFavos;

    colmeia->totalMel = nCelulas * 500;
    colmeia->totalPol = nCelulas * 20;

    for (int i = 0; i < colmeia->totalFavos; i++) {
        colmeia->favos[i].id = i;
        colmeia->favos[i].totalCelulas = celulasPorFavo;
        colmeia->favos[i].celulas = (Celula *)malloc(celulasPorFavo * sizeof(Celula));

        for (int j = 0; j < celulasPorFavo; j++) {
            switch (j % 4) {
                case 0: strcpy(colmeia->favos[i].celulas[j].tipo, "mel"); colmeia->favos[i].celulas[j].quantidade = 500; break;
                case 1: strcpy(colmeia->favos[i].celulas[j].tipo, "pol"); colmeia->favos[i].celulas[j].quantidade = 20; break;
                case 2: strcpy(colmeia->favos[i].celulas[j].tipo, "nec"); colmeia->favos[i].celulas[j].quantidade = 40; break;
                case 3: strcpy(colmeia->favos[i].celulas[j].tipo, "cri"); colmeia->favos[i].celulas[j].quantidade = 0; break;
            }
        }
    }
}

// Função para alimentar abelhas
void alimentarAbelhas(Colmeia *colmeia) {
    for (int i = 0; i < colmeia->totalAbelhas; i++) {
        if (colmeia->abelhas[i].viva && colmeia->abelhas[i].ultimaRefeicao >= 1440) {
            if (colmeia->totalPol >= POLEN_POR_REFEICAO && colmeia->totalMel >= MEL_POR_REFEICAO) {
                colmeia->totalPol -= POLEN_POR_REFEICAO;
                colmeia->totalMel -= MEL_POR_REFEICAO;
                colmeia->abelhas[i].ultimaRefeicao = 0;
            } else {
                colmeia->abelhas[i].viva = 0; // Morre por falta de alimento
            }
        }
    }
}

// Função para contar abelhas por tipo
void contarAbelhasPorTipo(Colmeia *colmeia, int *contagens) {
    for (int i = 0; i < 6; i++) {
        contagens[i] = 0;
    }

    for (int i = 0; i < colmeia->totalAbelhas; i++) {
        if (colmeia->abelhas[i].viva) {
            contagens[colmeia->abelhas[i].tipo]++;
        }
    }
}

// Função para gerar relatório detalhado
void gerarRelatorio(Colmeia *colmeia, int tempoAtual) {
    int dias = tempoAtual / 1440;
    int horas = (tempoAtual % 1440) / 60;
    int minutos = tempoAtual % 60;

    int contagens[6];
    contarAbelhasPorTipo(colmeia, contagens);

    printf("Relatorio colmeia: %d dia(s) %d hora(s) %d minuto(s)\n", dias, horas, minutos);
    printf(" fax nut con gua for zan rai\n");
    printf(" %3d %3d %3d %3d %3d %3d   1\n", contagens[0], contagens[1], contagens[2],
           contagens[3], contagens[4], contagens[5]);
    printf("    Favo   0:            celulas vazias:\n");
    printf("                                 usadas:\n");
}

// Função principal de simulação
void simularColmeia(Colmeia *colmeia, int minutosPorTemporada, int temporadas) {
    int tempoAtual = 0;

    for (int i = 0; i < abs(temporadas); i++) {
        alimentarAbelhas(colmeia);
        tempoAtual += minutosPorTemporada;
        gerarRelatorio(colmeia, tempoAtual);
    }
}

int main() {
    int nAbelhas, nCelulas, minutosPorTemporada, temporadas;

    // Leitura de dados
    scanf("%d %d %d %d", &nAbelhas, &nCelulas, &minutosPorTemporada, &temporadas);

    Colmeia colmeia;
    inicializarColmeiaDinamica(&colmeia, nAbelhas, nCelulas);

    simularColmeia(&colmeia, minutosPorTemporada, temporadas);

    liberarColmeia(&colmeia);
    return 0;
}
