#include <stdio.h>
#include <string.h>

#define NUM_LIVROS 3

typedef struct {
    char titulo[100];
    char autor[50];
    int ano;
    int paginas;
} Livro;

int main(void) {

    Livro biblioteca[NUM_LIVROS];

    for (int i = 0; i < NUM_LIVROS; i++) {
        printf("Indique o titulo do livro %d: ", i + 1);
        fgets(biblioteca[i].titulo, sizeof(biblioteca[i].titulo), stdin);
        biblioteca[i].titulo[strcspn(biblioteca[i].titulo, "\n")] = '\0';

        printf("Indique o autor do livro %d: ", i + 1);
        fgets(biblioteca[i].autor, sizeof(biblioteca[i].autor), stdin);
        biblioteca[i].autor[strcspn(biblioteca[i].autor, "\n")] = '\0';

        printf("Indique o ano do livro %d: ", i + 1);
        scanf("%d", &biblioteca[i].ano);

        printf("Indique o numero de páginas do livro %d: ", i + 1);
        scanf("%d", &biblioteca[i].paginas);

        while (getchar() != '\n')
            ;
    }

    for (int i = 0; i < NUM_LIVROS; i++) {
        if (biblioteca[i].paginas > 200) {
            printf("Título: %s\nAutor: %s\nAno: %d\nPáginas: %d", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano, biblioteca[i].paginas);
        }
    }
    return 0;
}
