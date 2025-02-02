#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int altura (no *r){
    if(!r)  return 0;

    int esq = altura(r->esq);
    int dir = altura(r->dir);

    return 1 + (esq > dir ? esq : dir);
}
