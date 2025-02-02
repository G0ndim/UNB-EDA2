#include <stdlib.h>
#include <stdio.h>

int aumentaTamanho(int M);

typedef struct {
    int *tb; // tabela hash
    int M;   // tamanho da tabela hash
    int N;   // total de chaves presentes na tabela
} TH;

int hash(int chave, int M) {
    return chave % M;
}

// Função auxiliar para redimensionar a tabela hash
void redimensionaTabela(TH *h) {
    int novoTamanho = aumentaTamanho(h->M);
    int *novaTabela = (int *)malloc(novoTamanho * sizeof(int));

    for (int i = 0; i < novoTamanho; i++) {
        novaTabela[i] = -1; // Inicializa com -1
    }

    for (int i = 0; i < h->M; i++) {
        if (h->tb[i] != -1) {
            int novaPos = hash(h->tb[i], novoTamanho);
            while (novaTabela[novaPos] != -1) {
                novaPos = (novaPos + 1) % novoTamanho;
            }
            novaTabela[novaPos] = h->tb[i];
        }
    }

    free(h->tb);
    h->tb = novaTabela;
    h->M = novoTamanho;
}

void THinsere(TH *h, int ch) {
    if (THbusca(h, ch)) {
        return;
    }

    if (h->N > h->M / 2) {
        redimensionaTabela(h);
    }

    int pos = hash(ch, h->M);
    while (h->tb[pos] != -1) {
        pos = (pos + 1) % h->M;
    }

    h->tb[pos] = ch;
    h->N++;
}

int THremove(TH *h, int ch) {
    int pos = hash(ch, h->M);

    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) {
            h->tb[pos] = -1;
            h->N--;

            pos = (pos + 1) % h->M;
            while (h->tb[pos] != -1) {
                int chaveReinserir = h->tb[pos];
                h->tb[pos] = -1;
                h->N--;
                THinsere(h, chaveReinserir);
                pos = (pos + 1) % h->M;
            }

            return 0;
        }
        pos = (pos + 1) % h->M;
    }
    return -1;
}

int THbusca(TH *h, int ch) {
    int pos = hash(ch, h->M);

    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) {
            return 1;
        }
        pos = (pos + 1) % h->M;
    }
    return 0;
}
