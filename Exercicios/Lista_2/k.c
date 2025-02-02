#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *minimo(no *r){
    no* temp = r;
    
    while(temp->esq != NULL){
        temp = temp->esq;
    }

    return temp;
}