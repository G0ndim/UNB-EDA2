#include <stdio.h>
#include <string.h>

#define TAMANHO_TABELA (1 << 21)

typedef struct{
    long long id;
    char food[11];
    int flag;
} Colonia;

long long funcao_hash(long long colonia, const char *alimento) {
    long long hs = 5381;
    while (*alimento){
        hs = ((hs << 5) + hs) + (unsigned char)(*alimento++);
    }

    long long h = colonia;
    h ^= hs << 16;
    h *= 2654435761;
    
    return h & (TAMANHO_TABELA - 1);
}

static Colonia tabelaHash[TAMANHO_TABELA];


int main(){
    long long idColonia;
    char comida[11];

    while(scanf("%lld %s", &idColonia, comida) == 2){
        long long pos = funcao_hash(idColonia, comida);

        while(1){
            if (!tabelaHash[pos].flag){
                tabelaHash[pos].flag = 1;
                tabelaHash[pos].id = idColonia;
                strcpy(tabelaHash[pos].food, comida);
                break;
            }
            else{
                if(tabelaHash[pos].id == idColonia && 
                  strcmp(tabelaHash[pos].food, comida) == 0){
                    printf("%lld\n", idColonia);
                    break;
                }
                
                pos = (pos + 1) & (TAMANHO_TABELA - 1);
            }
        }
    }

    return 0;
}
