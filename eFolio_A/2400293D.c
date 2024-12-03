#include <stdio.h>
#include <stdlib.h>

/* Valida se K está entre 2 e 100 */
int validar_K(int k) {
    if (k < 2 || k > 100) {
        printf("K tem de ser entre 2 e 100.\n");
        return 0;
    }
    return 1;
}

/* Verifica se a sequência é inválida */
int verificar_sequencia(int k, int vetor[], int tamanho) {
    int soma = 0, produto = 1;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
        produto *= vetor[i];
    }
    return soma <= k && produto >= k;
}

/* Verifica se a sequência é uma sequência de vitória */
int verificar_vitoria(int k, int vetor[], int tamanho) {
    int soma_diferencas = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            soma_diferencas += abs(vetor[i] - vetor[j]);
        }
    }
    return soma_diferencas == k;
}

/* Imprime a sequência atual */
void imprimir_sequencia(int vetor[], int tamanho, char jogador, int ultima) {
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    if (!ultima) {
        printf("[Joga %c]\n", jogador);
    } else {
        printf("\n");
    }
}

/* Processa uma jogada */
int processar_jogada(int vetor[], int *tamanho, int indice, int valor, int k) {
    if (valor == 0) {
        // Remover elemento
        if (indice < *tamanho) {
            for (int i = indice; i < *tamanho - 1; i++) {
                vetor[i] = vetor[i + 1];
            }
            (*tamanho)--;
        } else {
            return 0; // Jogada inválida
        }
    } else if (valor > 0) {
        // Atualizar valor no índice ou adicionar no final
        if (indice < *tamanho) {
            vetor[indice] = valor;
        } else if (*tamanho < 100) {
            vetor[*tamanho] = valor;
            (*tamanho)++;
        } else {
            return 0; // Jogada inválida
        }
    } else if (valor < 0) {
        // Inserir novo número no índice, deslocando para a direita
        if (indice <= *tamanho && *tamanho < 100) {
            for (int i = *tamanho; i > indice; i--) {
                vetor[i] = vetor[i - 1];
            }
            vetor[indice] = -valor;
            (*tamanho)++;
        } else {
            return 0; // Jogada inválida
        }
    }

    // Verificar se a sequência permanece válida
    if (!verificar_sequencia(k, vetor, *tamanho)) {
        return 0; // Sequência inválida
    }

    return 1; // Jogada válida
}

int main() {
    int k, vetor[100], tamanho = 2, jogadas = 0, max_jogadas;
    char jogador = 'A';
    int indice, valor;

    printf("Indique K:\n");
    scanf("%d", &k);

    if (!validar_K(k)) {
        return 1;
    }

    vetor[0] = k / 2;
    vetor[1] = k / 2;
    max_jogadas = k;

    imprimir_sequencia(vetor, tamanho, jogador, 0);

    while (jogadas < max_jogadas) {
        printf("Jogada (indice valor):\n");
        scanf("%d %d", &indice, &valor);

        if (!processar_jogada(vetor, &tamanho, indice, valor, k)) {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogada inválida. Jogador %c perdeu.\n", jogador);
            return 0;
        }

        if (verificar_vitoria(k, vetor, tamanho)) {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogador %c ganhou.\n", jogador);
            return 0;
        }

        if (valor >= 0 || indice >= tamanho) {
            jogador = (jogador == 'A') ? 'B' : 'A';
        }

        imprimir_sequencia(vetor, tamanho, jogador, 0);
        jogadas++;
    }

    printf("Empate.\n");
    return 0;
}
