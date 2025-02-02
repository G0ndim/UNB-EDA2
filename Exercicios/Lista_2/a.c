#include <stdlib.h>
#include <stdio.h>


typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; // tabela hash
    int M;      // tamanho da tabela hash
    int N;      // total de chaves presentes na tabela
} TH;

celula *criaCelula(int dado) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = dado;
    nova->prox = NULL;
    return nova;
}

// Função hash modular
int hash(int chave, int M) {
    return chave % M;
}

void THinsere(TH *h, int ch) {
    int idx = hash(ch, h->M);
    celula *atual = h->tb[idx].prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            return;
        }
        atual = atual->prox;
    }

    celula *nova = criaCelula(ch);
    nova->prox = h->tb[idx].prox;
    h->tb[idx].prox = nova;
    h->N++;
}

int THremove(TH *h, int ch) {
    int idx = hash(ch, h->M);
    celula *atual = &h->tb[idx];
    
    while (atual->prox != NULL) {
        if (atual->prox->dado == ch) {
            celula *remover = atual->prox;
            atual->prox = remover->prox;
            free(remover);
            h->N--;
            return 0;
        }
        atual = atual->prox;
    }
    return -1;
}

int THbusca(TH *h, int ch) {
    int idx = hash(ch, h->M);
    celula *atual = h->tb[idx].prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}
