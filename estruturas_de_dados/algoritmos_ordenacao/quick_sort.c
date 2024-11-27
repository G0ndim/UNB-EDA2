#include <stdlib.h>
#include <stdio.h>

/*
    COMPLEXIDADE: O(n log n) melhor e médio,  
    O(n²) pior caso (para vetores quase ordenados,
    com muitos elementos repetidos ou ordenado de forma
    decrescente ele faz n²/2 comparacões. Pode ser 
    otimizado com a técnica da mediana de três)
    
    -> f(n) = n * f(1) + logn * n
    -> É in-place (possui somente recursões 
    proporcionais a log n)
    -> Não é estavel (possui trocas com saltos)
    -> Não é adaptativo (ordenação não ajuda a 
    melhorar o  desempenho)
*/


int swap(int *v1, int *v2){
    int temp = *v2;
    *v2 = *v1;
    *v1 = temp;
}


int separa(int* v, int l, int r){
    int pivo = v[r];

    int j = l;

    for(int k = l; k < r; k++){
        if(v[k] <= pivo)
            swap(&v[k], &v[j++]);
    }

    swap(&v[j], &v[r]);

    return j;
}

void quick_sort(int *v, int l, int r){
    if(r <= l) return;

    // Otimização: Mediana de três (tenta inserir 
    // a mediana na direita)
    int meio = (l+r) / 2;
    if(v[meio] > v[r])  swap(v[meio], v[r]);
    if(v[l] > v[meio])    swap(v[l], v[meio]);
    if(v[r] > v[meio])    swap(v[meio], v[r]);

    int p = separa(v, l, r);
    quick_sort(v, l, p-1);
    quick_sort(v, p+1, r);
}

// int main(){

//     int v[3]  =  {2, 4, 3};

//     quick_sort(v, 0, 2);

//     for(int i = 0; i < 3; i++){
//         printf("%d ", v[i]);
//     }

//     return 0;
// }