#include <stdio.h>

// Função para validar o valor de K
int validar_k(int k) {
    if (k < 2 || k > 100) {
        printf("K tem de ser entre 2 e 100.\n");
        return 0; // Valor inválido
    }
    return 1; // Valor válido
}

// Função para gerar a sequência inicial
void gerar_sequencia_inicial(int k, int sequencia[]) {
    sequencia[0] = k / 2;
    sequencia[1] = k / 2;
}

// Função para imprimir a sequência
void imprimir_sequencia(int sequencia[], int tamanho) {
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int k;
    int sequencia[2]; // A sequência inicial terá sempre dois elementos para a alínea A

    printf("Indique K: ");
    scanf("%d", &k);

    // Validar o valor de K
    if (!validar_k(k)) {
        return 1; // Encerrar o programa caso K seja inválido
    }

    // Gerar e imprimir a sequência inicial
    gerar_sequencia_inicial(k, sequencia);
    imprimir_sequencia(sequencia, 2);

    return 0;
}
