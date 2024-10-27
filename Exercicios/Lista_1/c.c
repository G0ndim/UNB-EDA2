#include <stdio.h>
#include <string.h>

int verifica_sigla(char *aeroporto, char *sigla) {
    int i = 0, j = 0;
    int tamanhoAeroporto = strlen(aeroporto);
    int tamanhoSigla = strlen(sigla);

    if (sigla[2] == 'X') {
        tamanhoSigla = 2;
    }

    while (i < tamanhoAeroporto && j < tamanhoSigla) {
        if (aeroporto[i] == sigla[j] + 32) {
            j++;  
        }
        i++;
    }

    return (j == tamanhoSigla);
}

int main() {
    char aeroporto[100005];
    char sigla[4];

    scanf("%s", aeroporto);
    scanf("%s", sigla);

    if (verifica_sigla(aeroporto, sigla)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
