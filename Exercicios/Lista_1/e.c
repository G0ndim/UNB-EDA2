#include <stdio.h>
#include <stdlib.h>

int main() {
    int D;  
    scanf("%d", &D);

    while (!feof(stdin)) {
        int ano, semestre, m;
        
        if (scanf("%d %d %d", &ano, &semestre, &m) != 3)
            break;

        int maiorReprovacao = 0;
        int disciplinasMax[D];
        int numDisciplinasMax = 0;

        for (int i = 0; i < m; i++) {
            int codigo, matriculados, aprovados;
            scanf("%d %d %d", &codigo, &matriculados, &aprovados);

            int reprovados = matriculados - aprovados;

            if (reprovados > maiorReprovacao) {
                maiorReprovacao = reprovados;
                disciplinasMax[0] = codigo;
                numDisciplinasMax = 1;
            } else if (reprovados == maiorReprovacao) {
                disciplinasMax[numDisciplinasMax++] = codigo;
            }
        }

        printf("%d/%d\n", ano, semestre);

        for (int i = 0; i < numDisciplinasMax - 1; i++) {
            for (int j = i + 1; j < numDisciplinasMax; j++) {
                if (disciplinasMax[i] > disciplinasMax[j]) {
                    int temp = disciplinasMax[i];
                    disciplinasMax[i] = disciplinasMax[j];
                    disciplinasMax[j] = temp;
                }
            }
        }

        for (int i = 0; i < numDisciplinasMax; i++) {
            printf("%d ", disciplinasMax[i]);
        }
        printf("\n\n");
    }

    return 0;
}
