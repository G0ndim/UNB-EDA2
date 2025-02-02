#include <stdio.h>
#include <string.h>

// Função para construir o percurso pós-fixo
void construirPosfixo(char *prefixo, char *infixo, int n, char *posfixo, int *index) {
    if (n <= 0) {
        return;
    }

    // A raiz é o primeiro caractere do percurso prefixo
    char raiz = prefixo[0];

    // Localiza a posição da raiz no percurso infixo
    int posRaiz;
    for (posRaiz = 0; posRaiz < n; posRaiz++) {
        if (infixo[posRaiz] == raiz) {
            break;
        }
    }

    // Constrói o percurso pós-fixo da subárvore esquerda
    construirPosfixo(prefixo + 1, infixo, posRaiz, posfixo, index);

    // Constrói o percurso pós-fixo da subárvore direita
    construirPosfixo(prefixo + 1 + posRaiz, infixo + posRaiz + 1, n - posRaiz - 1, posfixo, index);

    // Adiciona a raiz ao percurso pós-fixo
    posfixo[(*index)++] = raiz;
}

int main() {
    int C;
    scanf("%d", &C); // Número de casos de teste

    while (C--) {
        int N;
        char prefixo[53], infixo[53], posfixo[53];
        scanf("%d %s %s", &N, prefixo, infixo);

        int index = 0;
        construirPosfixo(prefixo, infixo, N, posfixo, &index);
        posfixo[index] = '\0'; // Adiciona o terminador de string

        printf("%s\n", posfixo); // Imprime o percurso pós-fixo
    }

    return 0;
}
