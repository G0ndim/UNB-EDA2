#include <stdlib.h>
#include <stdio.h>


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