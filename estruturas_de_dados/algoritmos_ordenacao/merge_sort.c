#include <stdlib.h>
#include <stdio.h>

/*
    COMPLEXIDADE: O(n Log n) em todos os casos
    -> f(n) = n * f(1) + n * log n
    -> Não é in-place! Memória extra proporcional a N
    -> Não é adaptativo (uma pré ordenação não diminui
    as divisões, nem as divisões no merge)
    -> É estavel (mantém a ordem relativa dos elementos)
*/

void merge(int* v, int l, int r, int m){
    
    int* aux = malloc(sizeof(int) * (r+1-l));

    int i = l, j = m+1, k = 0;

    while(i <= m && j <= r){
        if(v[i] <= v[j]){
            aux[k++] = v[i++];
        }
        else{
            aux[k++] = v[j++];
        }
    }

    while(i <= m)  aux[k++] = v[i++];
    while(j <= r)  aux[k++]  = v[j++];

    for(k = 0, i = l; i <= r; i++, k++){
        v[i] = aux[k];
    }

    free(aux);
}

void merge_sort(int* v, int l, int r){
    if(r <= l) return;

    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio+1, r);
    merge(v, l, r, meio);
}

// int main(){

//     int v[3]  =  {2, 4, 3};

//     merge_sort(v, 0, 2);

//     for(int i = 0; i < 3; i++){
//         printf("%d ", v[i]);
//     }

//     return 0;
// }