#include <stdio.h>

void Romano(int num) {
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (num >= valores[i]) {
            printf("%s", simbolos[i]);
            num -= valores[i];
        }
    }
    printf("\n");
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);
        Romano(valor);  
    }

    return 0;
}
