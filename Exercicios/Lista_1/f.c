#include <stdio.h>

int main() {
    int D, A, N;
    
    scanf("%d", &D);
    scanf("%d", &A);
    scanf("%d", &N);
    
    int diasRestantes = 32 - N;
    
    int diariaNoDiaDeChegada = D + (N - 1) * A;
    
    int total = diasRestantes * diariaNoDiaDeChegada;
    
    printf("%d\n", total);
    
    return 0;
}
