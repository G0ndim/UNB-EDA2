#include <stdio.h>
#include <stdlib.h>

typedef struct cabeca cabeca;
cabeca* criar_lista();
No* desenfileira(cabeca* inicio);
void enfileira(cabeca* fila, No* node);


typedef struct Node{
    int dado;
    No *esq;
    No *dir;
} No;

void *pre_ordem(No *p){
    if(p != NULL){
        printf("%d\n", p->dado);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void *in_ordem(No *p){
    if(p != NULL){
        in_ordem(p->esq);
        printf("%d\n", p->dado);
        in_ordem(p->dir);
    }
}

void *pos_ordem(No *p){
    if(p != NULL){
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        printf("%d\n", p->dado);
    }
}

void percurso_em_largura (No *raiz) {
    cabeca *f = criar_lista ();
    enfileira (f , raiz );

    while(!vazia(f)) {
        raiz = desenfileira(f);
        if ( raiz != NULL ) {
            enfileira (f , raiz-> esq );
            enfileira (f , raiz-> dir );
            printf (" %d " , raiz-> dado );
        }
    }
}