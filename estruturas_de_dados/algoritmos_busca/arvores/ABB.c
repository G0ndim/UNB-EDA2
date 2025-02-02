#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dado;
    no *esq;
    no *dir;
} no;

no* busca_abb(no* raiz, int x){
    if(raiz != NULL && raiz->dado == x) return raiz;

    if(raiz->dado < x){
        busca_abb(raiz->dir, x);
    }
    else{
        busca_abb(raiz->esq, x);
    }
}