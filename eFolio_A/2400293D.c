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

/* Calcula a soma dos números na sequência */
int calcular_soma(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma;
}

/* Jogador Artificial */
int jogada_artificial(int vetor[], int *tamanho, int k, int *indice_resultado, int *valor_resultado) {
    int melhor_indice = -1, melhor_valor = 0;
    int menor_tamanho = 10000; // Um valor suficientemente grande
    int soma_atual = calcular_soma(vetor, *tamanho);

    // Iterar sobre os índices
    for (int i = 0; i < *tamanho; i++) {
        int valor_atual = vetor[i];

        // Testar remoção ou redução
        for (int v = 0; v < valor_atual; v++) {
            vetor[i] = v;
            if (verificar_sequencia(k, vetor, *tamanho)) {
                if (verificar_vitoria(k, vetor, *tamanho)) {
                    *indice_resultado = i;
                    *valor_resultado = v;
                    vetor[i] = valor_atual;
                    return 1; // Vitória encontrada
                }
                if (*tamanho < menor_tamanho) {
                    melhor_indice = i;
                    melhor_valor = v;
                    menor_tamanho = *tamanho;
                }
            }
            vetor[i] = valor_atual; // Restaurar o valor original
        }

        // Testar incremento
        for (int v = valor_atual + 1; v <= valor_atual + (k - soma_atual); v++) {
            vetor[i] = v;
            if (verificar_sequencia(k, vetor, *tamanho)) {
                if (verificar_vitoria(k, vetor, *tamanho)) {
                    *indice_resultado = i;
                    *valor_resultado = v;
                    vetor[i] = valor_atual;
                    return 1; // Vitória encontrada
                }
                if (*tamanho < menor_tamanho) {
                    melhor_indice = i;
                    melhor_valor = v;
                    menor_tamanho = *tamanho;
                }
            }
            vetor[i] = valor_atual; // Restaurar o valor original
        }
    }

    // Testar adição de novos números
    for (int v = -1; v >= -(k - soma_atual); v--) {
        if (*tamanho < 100) {
            vetor[*tamanho] = -v;
            (*tamanho)++;
            if (verificar_sequencia(k, vetor, *tamanho)) {
                if (verificar_vitoria(k, vetor, *tamanho)) {
                    *indice_resultado = *tamanho - 1;
                    *valor_resultado = v;
                    (*tamanho)--;
                    return 1; // Vitória encontrada
                }
                if (*tamanho < menor_tamanho) {
                    melhor_indice = *tamanho - 1;
                    melhor_valor = v;
                    menor_tamanho = *tamanho;
                }
            }
            (*tamanho)--; // Reverter a adição
        }
    }

    // Aplicar a melhor jogada encontrada
    if (melhor_indice != -1) {
        *indice_resultado = melhor_indice;
        *valor_resultado = melhor_valor;
        return 1;
    }

    return 0; // Nenhuma jogada possível
}

int main() {
    int k, vetor[100], tamanho = 2, jogadas = 0;
    char jogador = 'A';
    int indice, valor;

    printf("Indique K:\n");
    scanf("%d", &k);

    if (!validar_K(k)) {
        return 1;
    }

    vetor[0] = k / 2;
    vetor[1] = k / 2;

    imprimir_sequencia(vetor, tamanho, jogador, 0);

    while (jogadas < k) {
        printf("Jogada (indice valor):\n");
        scanf("%d %d", &indice, &valor);

        if (indice == -2 && valor == -2) {
            int indice_artificial, valor_artificial;
            if (!jogada_artificial(vetor, &tamanho, k, &indice_artificial, &valor_artificial)) {
                printf("Jogada artificial: Nenhuma jogada possível. Empate.\n");
                return 0;
            }
            printf("Jogada artificial: %d %d\n", indice_artificial, valor_artificial);
            vetor[indice_artificial] = valor_artificial;
        } else if (indice >= 0 && indice < tamanho) {
            vetor[indice] = valor;
        } else {
            printf("Jogada inválida. Jogador %c perdeu.\n", jogador);
            return 0;
        }

        if (!verificar_sequencia(k, vetor, tamanho)) {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogador %c perdeu.\n", jogador);
            return 0;
        }

        if (verificar_vitoria(k, vetor, tamanho)) {
            imprimir_sequencia(vetor, tamanho, jogador, 1);
            printf("Jogador %c ganhou.\n", jogador);
            return 0;
        }

        jogador = (jogador == 'A') ? 'B' : 'A';
        imprimir_sequencia(vetor, tamanho, jogador, 0);
        jogadas++;
    }

    printf("Empate.\n");
    return 0;
}
