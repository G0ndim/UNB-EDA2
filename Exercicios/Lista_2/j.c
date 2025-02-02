#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *maximo(no *r){
    no* temp = r;
    
    while(temp->dir != NULL){
        temp = temp->dir;
    }

    return temp;
}