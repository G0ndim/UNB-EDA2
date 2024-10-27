#include <stdio.h>

int main() {
    float D, notas[7], soma = 0.0;
    float maior = 0.0, menor = 10.0;
    
    scanf("%f", &D);
    
    for (int i = 0; i < 7; i++) {
        scanf("%f", &notas[i]);
        soma += notas[i];
        
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    
    soma -= (maior + menor);
    
    float nota_final = (soma / 5.0) * D;
    
    printf("%.1f\n", nota_final);
    
    return 0;
}
