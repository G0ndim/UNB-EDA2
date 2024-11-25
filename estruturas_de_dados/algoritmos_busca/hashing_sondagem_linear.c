#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 11

typedef struct {
    int chave;        
    char* dado;       
} celula;

int hash_function(int key) {
    // (((a*x + b) % p) % M)
    // a e b = #'s aleatorios, p = # primo,
    // x = chave, M = tamanho da tabela 
    return (((10 * key + 27) % 17) % TABLE_SIZE);
}

celula* create_node(int key, const char* data) {
    celula* new_node = malloc(sizeof(celula));
    if (new_node == NULL) {
        perror("Erro ao alocar memória para a célula");
        exit(EXIT_FAILURE);
    }
   
    new_node->chave = key;
    new_node->dado = strdup(data);
    
    return new_node;
}

celula** create_hash_table() {
    celula** table = calloc(TABLE_SIZE, sizeof(celula));
    if (!table) {
        perror("Erro ao alocar memória para a tabela hash");
        exit(EXIT_FAILURE);
    }
    return table;
}

void add_to_hash_table(celula** table, celula* node) {
    int hash = hash_function(node->chave);

    // Sondagem linear: procurar até encontrar uma célula livre
    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (hash + i) % TABLE_SIZE;

        if (!table[index]) {
            table[index] = node;
            return;
        }
    }

    printf("Erro: tabela hash cheia. Não foi possível inserir a chave %d\n", node->chave);
}

celula* search_in_hash_table(celula** table, int key) {
    int hash = hash_function(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (hash + i) % TABLE_SIZE;

        // Se a posição está ocupada e a chave é igual
        if (table[index] && table[index]->chave == key) {
            return table[index]; // Retorna a posição
        }

        // Se a posição está desocupada, a chave não está na tabela
        if (!table[index]) {
            break;
        }
    }

    return NULL; // Chave não encontrada
}


void print_table(celula** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        if (table[i]) {
            printf("Chave=%d, Dado=%s\n", table[i]->chave, table[i]->dado);
        } else {
            printf("---\n");
        }
    }
}


int main() {
    celula** tabela = create_hash_table();

    celula* node1 = create_node(1, "Pedro");
    celula* node2 = create_node(2, "Ana");
    celula* node3 = create_node(13, "Jose");
    celula* node4 = create_node(15, "Maria");
    celula* node5 = create_node(23, "Joao");
    celula* node6 = create_node(17, "Julia");
    celula* node7 = create_node(224, "Osvaldo");
    celula* node8 = create_node(89, "Claudio");
    celula* node9 = create_node(11, "Cleide");

    add_to_hash_table(tabela, node1);
    add_to_hash_table(tabela, node2);
    add_to_hash_table(tabela, node3);
    add_to_hash_table(tabela, node4);
    add_to_hash_table(tabela, node5);
    add_to_hash_table(tabela, node6);
    add_to_hash_table(tabela, node7);
    add_to_hash_table(tabela, node8);
    add_to_hash_table(tabela, node9);

    print_table(tabela);
    
    return 0;
}
