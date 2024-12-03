#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// Função para validar o valor de K (reutilizada da alínea A)
int validar_k(int k) {
    if (k < 2 || k > 100) {
        printf("K tem de ser entre 2 e 100.\n");
        return 0;
    }
    return 1;
}

// Função para verificar a validade da sequência
int validar_sequencia(int k, int sequencia[], int tamanho) {
    int soma = 0, produto = 1;
    for (int i = 0; i < tamanho; i++) {
        soma += sequencia[i];
        produto *= sequencia[i];
    }

    if (soma > k || produto < k) {
        return 0; // Sequência inválida
    }
    return 1; // Sequência válida
}

// Função para verificar se a sequência é de vitória
int verificar_vitoria(int k, int sequencia[], int tamanho) {
    int soma_diferencas = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            soma_diferencas += abs(sequencia[i] - sequencia[j]);
        }
    }

    return (soma_diferencas == k); // Retorna 1 se for vitória, 0 caso contrário
}

// Função para ler a sequência de entrada do utilizador
int ler_sequencia(int sequencia[], int max_tamanho) {
    int tamanho = 0, valor;
    printf("Indique uma sequencia de numeros inteiros positivos, terminando com 0: ");
    while (tamanho < max_tamanho) {
        scanf("%d", &valor);
        if (valor == 0) {
            break;
        }
        if (valor < 1) {
            printf("Os valores devem ser positivos.\n");
            return -1; // Sequência inválida
        }
        sequencia[tamanho++] = valor;
    }
    return tamanho; // Retorna o tamanho da sequência lida
}

// Função principal
int main() {
    int k;
    int sequencia[100]; // Limite máximo de 100 números na sequência

    printf("Indique K: ");
    scanf("%d", &k);

    // Validar o valor de K
    if (!validar_k(k)) {
        return 1;
    }

    // Ler a sequência do utilizador
    int tamanho = ler_sequencia(sequencia, 100);
    if (tamanho == -1) {
        return 1; // Sequência inválida
    }

    // Validar a sequência
    if (!validar_sequencia(k, sequencia, tamanho)) {
        printf("Sequencia invalida\n");
        return 0;
    }

    // Verificar se é uma sequência de vitória
    if (verificar_vitoria(k, sequencia, tamanho)) {
        printf("Sequencia vitoria\n");
    } else {
        printf("Sequencia valida\n");
    }

    return 0;
}
