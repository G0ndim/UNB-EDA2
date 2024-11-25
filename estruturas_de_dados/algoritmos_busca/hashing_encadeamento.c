#include <stdlib.h>
#include <stdio.h>
#include <string.h>  // strdup

#define TABLE_SIZE 11

typedef struct Node celula;
struct Node {
    int chave;
    char* dado;  //  string
    celula* prox;
};

int hash_function(int key) {
    // (((a*x + b) % p) % M)
    // a e b = #'s aleatorios, p = # primo,
    // x = chave, M = tamanho da tabela 
    return (((10 * key + 27) % 17) % TABLE_SIZE);
}

celula** create_hash_table() {
    return calloc(TABLE_SIZE, sizeof(celula*));
}

celula* create_node(int key, const char* data) {
    celula* new_node = malloc(sizeof(celula));
    if (new_node == NULL) {
        perror("Erro ao alocar memória para a célula");
        exit(EXIT_FAILURE);
    }
   
    new_node->chave = key;
    new_node->dado = strdup(data);
    new_node->prox = NULL;
    
    return new_node;
}

void add_to_hash_table(celula** table, celula* node) {
    int hash = hash_function(node->chave);

    if (table[hash] == NULL) {
        table[hash] = node;
    } else {
        node->prox = table[hash];
        table[hash] = node;
    }
}

celula* buscar_elemento(celula** tabela, int key){
    return tabela[hash_function(key)];
}

void print_table(celula** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d. ", i);
        if (table[i] == NULL) 
            printf("---\n");
        else {
            celula* temp = table[i];
            while (temp != NULL) {
                printf("%s -> ", temp->dado);
                temp = temp->prox;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    celula** tabela = create_hash_table();

    celula* node1 = create_node(1, "Ana");
    celula* node2 = create_node(2, "Pedro");
    celula* node3 = create_node(13, "Maria");
    celula* node4 = create_node(15, "Jose");
    celula* node5 = create_node(23, "Alberto");

    add_to_hash_table(tabela, node1);
    add_to_hash_table(tabela, node2);
    add_to_hash_table(tabela, node3);
    add_to_hash_table(tabela, node4);
    add_to_hash_table(tabela, node5);

    print_table(tabela);


    // Liberação de memória
    // for (int i = 0; i < TABLE_SIZE; i++) {
    //     celula* temp = tabela[i];
    //     while (temp) {
    //         celula* to_free = temp;
    //         temp = temp->prox;
    //         free(to_free->dado);
    //         free(to_free);
    //     }
    // }
    // free(tabela);

    return 0;
}
