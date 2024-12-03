#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printSequence(int sequence[], int size) {
    printf("Sequence: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int validateSequence(int sequence[], int size, int K) {
    int sum = 0, product = 1;
    for (int i = 0; i < size; i++) {
        sum += sequence[i];
        product *= sequence[i];
    }
    return (sum <= K && product >= K);
}

int checkWin(int sequence[], int size, int K) {
    int sumOfDifferences = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            sumOfDifferences += abs(sequence[i] - sequence[j]);
        }
    }
    return (sumOfDifferences == K);
}

int main() {
    int K, turn = 0; // turn: 0 for Player A, 1 for Player B
    printf("Input K: ");
    scanf("%d", &K);

    if (K < 2 || K > 100) {
        printf("K must be between 2 and 100.\n");
        return 1;
    }

    int sequence[MAX_SIZE];
    int size = 2;
    sequence[0] = sequence[1] = K / 2;

    printSequence(sequence, size);

    int consecutiveInsertRemove = 0, currentPlayer = 0;
    while (1) {
        printf("Move (index value) [Player %c's turn]: ", currentPlayer == 0 ? 'A' : 'B');
        int index, value;
        scanf("%d %d", &index, &value);

        if (index > size) {
            printf("Invalid index.\n");
            continue;
        }

        // Perform the operation
        if (value == 0) { // Remove value
            if (index < size) {
                for (int i = index; i < size - 1; i++) {
                    sequence[i] = sequence[i + 1];
                }
                size--;
            }
        } else if (index == size) { // Add value at the end
            sequence[size++] = value;
            consecutiveInsertRemove = 0;
        } else if (index < size) { // Replace or insert
            sequence[index] = value;
        }

        printSequence(sequence, size);

        // Validate sequence
        if (!validateSequence(sequence, size, K)) {
            printf("Invalid sequence. Player %c lost.\n", currentPlayer == 0 ? 'A' : 'B');
            break;
        }

        // Check winning condition
        if (checkWin(sequence, size, K)) {
            printf("Player %c won!\n", currentPlayer == 0 ? 'A' : 'B');
            break;
        }

        // Manage turns
        if (value == 0 || index < size) {
            if (consecutiveInsertRemove == 0) {
                consecutiveInsertRemove++;
            } else {
                currentPlayer = 1 - currentPlayer;
                consecutiveInsertRemove = 0;
            }
        } else {
            currentPlayer = 1 - currentPlayer;
        }
    }

    return 0;
}
