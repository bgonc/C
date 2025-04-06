#ifndef CONTEUDOS_H
#define CONTEUDOS_H

#define MAX_TITULO 100
#define MAX_CATEGORIA 50

typedef struct {
    char titulo[MAX_TITULO];
    char categoria[MAX_CATEGORIA];
    int duracao;
    int classificacaoEtaria;
    int visualizacoes;
} Conteudo;

void lerConteudosCSV(const char *nomeFicheiro, Conteudo **lista, int *num);
void gravarConteudosCSV(const char *nomeFicheiro, Conteudo *lista, int num);
void listarConteudos(Conteudo *lista, int num);
void adicionarConteudo(Conteudo **lista, int *num);
void editarConteudo(Conteudo *lista, int num);
void removerConteudo(Conteudo **lista, int *num);
void pesquisarConteudo(Conteudo *lista, int num);

#endif
