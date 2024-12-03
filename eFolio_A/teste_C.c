#include <stdio.h>
#include <stdlib.h> // Para abs()

// Funções auxiliares
int validar_k(int k) {
    if (k < 2 || k > 100) {
        printf("K tem de ser entre 2 e 100.\n");
        return 0;
    }
    return 1;
}

int validar_sequencia(int k, int sequencia[], int tamanho) {
    int soma = 0, produto = 1;
    for (int i = 0; i < tamanho; i++) {
        soma += sequencia[i];
        produto *= sequencia[i];
    }
    return (soma <= k && produto >= k);
}

int verificar_vitoria(int k, int sequencia[], int tamanho) {
    int soma_diferencas = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            soma_diferencas += abs(sequencia[i] - sequencia[j]);
        }
    }
    return (soma_diferencas == k);
}

// Função para alternar jogadores
void alternar_jogador(char *jogador, int *inserir_remover_contador) {
    if (*inserir_remover_contador >= 2) {
        *jogador = (*jogador == 'A') ? 'B' : 'A';
        *inserir_remover_contador = 0;
    }
}

// Função para processar uma jogada
int processar_jogada(int k, int sequencia[], int *tamanho, char *jogador, int *inserir_remover_contador) {
    int indice, valor;
    printf("Jogada (indice valor):\n");
    scanf("%d %d", &indice, &valor);

    if (indice >= *tamanho) {
        // Adicionar no final
        sequencia[*tamanho] = valor;
        (*tamanho)++;
        *inserir_remover_contador = 0; // Reseta o contador
        *jogador = (*jogador == 'A') ? 'B' : 'A'; // Alterna jogador
        return validar_sequencia(k, sequencia, *tamanho);
    }

    if (indice >= 0 && indice < *tamanho) {
        if (valor == 0) {
            // Remover
            for (int i = indice; i < *tamanho - 1; i++) {
                sequencia[i] = sequencia[i + 1];
            }
            (*tamanho)--;
            (*inserir_remover_contador)++;
        } else if (valor < 0) {
            // Inserir
            for (int i = *tamanho; i > indice; i--) {
                sequencia[i] = sequencia[i - 1];
            }
            sequencia[indice] = -valor;
            (*tamanho)++;
            (*inserir_remover_contador)++;
        } else {
            // Substituir
            sequencia[indice] = valor;
            *inserir_remover_contador = 0;
            *jogador = (*jogador == 'A') ? 'B' : 'A';
        }
        return validar_sequencia(k, sequencia, *tamanho);
    }

    printf("Jogada inválida. Índice fora dos limites.\n");
    return 0;
}

// Função para imprimir a sequência
void imprimir_sequencia(int sequencia[], int tamanho, char jogador) {
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("[Joga %c]\n", jogador);
}

// Função principal
int main() {
    int k, tamanho = 2, jogadas = 0, max_jogadas, inserir_remover_contador = 0;
    char jogador = 'A';
    int sequencia[100];

    printf(" Indique K:\n");
    scanf("%d", &k);

    if (!validar_k(k)) {
        return 1;
    }

    sequencia[0] = k / 2;
    sequencia[1] = k / 2;

    imprimir_sequencia(sequencia, tamanho, jogador);

    max_jogadas = k;
    while (jogadas < max_jogadas) {
        if (!processar_jogada(k, sequencia, &tamanho, &jogador, &inserir_remover_contador)) {
            imprimir_sequencia(sequencia, tamanho, jogador);
            printf("Jogador %c perdeu.\n", jogador);
            return 0;
        }

        if (verificar_vitoria(k, sequencia, tamanho)) {
            imprimir_sequencia(sequencia, tamanho, jogador);
            printf("Jogador %c ganhou.\n", jogador);
            return 0;
        }

        jogadas++;
        alternar_jogador(&jogador, &inserir_remover_contador);
        imprimir_sequencia(sequencia, tamanho, jogador);
    }

    imprimir_sequencia(sequencia, tamanho, jogador);
    printf("Empate.\n");
    return 0;
}
