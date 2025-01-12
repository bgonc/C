#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o cabeçalho do relatório.
void imprimirCabecalho(void)
{
    printf("Relatorio colmeia:\n");
    printf(" fax nut con gua for zan rai ovo lar pup mel pol nec cri zan rea\n");
}

// Função para distribuir as abelhas operárias.
void distribuirOperarias(int totalAbelhas,
                         int *fax, int *nut, int *con, int *gua, int *forr)
{
    int abelhasPorDia = totalAbelhas / 40;
    int cicloCompleto = abelhasPorDia / 5;
    int resto = abelhasPorDia % 5;

    *fax = (cicloCompleto + (resto > 0 ? 1 : 0)) * 40;
    *nut = (cicloCompleto + (resto > 1 ? 1 : 0)) * 40;
    *con = (cicloCompleto + (resto > 2 ? 1 : 0)) * 40;
    *gua = (cicloCompleto + (resto > 3 ? 1 : 0)) * 40;
    *forr = (cicloCompleto + (resto > 4 ? 1 : 0)) * 40;
}

// Função para imprimir a distribuição das abelhas.
void imprimirDistribuicao(int fax, int nut, int con, int gua, int forr,
                          int zangoes, int rainha)
{
    printf("  %d  %d  %d  %d  %d  %d   %d\n",
           fax, nut, con, gua, forr, zangoes, rainha);
}

// Função para verificar se há abelhas suficientes (>= 200).
// Se houver, distribui e imprime. Se não, imprime apenas uma linha em branco.
void verificaNumAbelhas(int nAbelhas)
{
    if (nAbelhas < 200)
    {
        printf("\n");
    }
    else
    {
        int fax = 0, nut = 0, con = 0, gua = 0, forr = 0;
        distribuirOperarias(nAbelhas, &fax, &nut, &con, &gua, &forr);
        // 40 zangões e 1 rainha
        imprimirDistribuicao(fax, nut, con, gua, forr, 40, 1);
    }
}

// Função para imprimir as linhas finais sobre favos e células
void imprimirFavos(void)
{
    printf("    Favo   0:            celulas vazias:\n");
    printf("                                 usadas:\n");
}

int main()
{
    int nAbelhas, nCelulas, minutos, temporadas;

    // printf("Quantidade de abelhas: ");
    scanf("%d", &nAbelhas);
    // printf("Quantidade de celulas: ");
    scanf("%d", &nCelulas);
    // printf("Minutos por temporada: ");
    scanf("%d", &minutos);
    // printf("Temporadas: ");
    scanf("%d", &temporadas);

    imprimirCabecalho();

    verificaNumAbelhas(nAbelhas);

    imprimirFavos();

    return 0;
}
