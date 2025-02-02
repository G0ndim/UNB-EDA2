#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *inserir (no *r, int x){
    if(!r){
        no* novo = malloc(sizeof(no));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        
        return novo;
    }

    else if(x < r->chave)   r->esq = inserir(r->esq, x);
    else if(x > r->chave)   r->dir = inserir(r->dir, x);

    return r;
}