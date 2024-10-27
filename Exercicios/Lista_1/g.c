#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char alteracoes[1000][101];
    int topo;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = -1;
}

int vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha *pilha, const char *alteracao) {
    if (pilha->topo < 1000 - 1) {
        pilha->topo++;
        strncpy(pilha->alteracoes[pilha->topo], alteracao, 100);
        pilha->alteracoes[pilha->topo][100] = '\0';
    }
}

const char* desempilhar(Pilha *pilha) {
    if (vazia(pilha)) {
        return "NULL";
    }
    return pilha->alteracoes[pilha->topo--];
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    char comando[110];

    while (fgets(comando, sizeof(comando), stdin) != NULL) {
        if (strncmp(comando, "inserir ", 8) == 0) {
            empilhar(&pilha, comando + 8);
        } else if (strncmp(comando, "desfazer", 7) == 0) {
            printf("%s\n", desempilhar(&pilha));
        }
    }

    return 0;
}
