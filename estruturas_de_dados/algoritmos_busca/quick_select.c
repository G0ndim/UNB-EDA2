#include <stdlib.h>
#include <stdio.h>


int swap(int *v1, int *v2){
    int temp = *v2;
    *v2 = *v1;
    *v1 = temp;
}

int separa(int *v, int l, int r){
    int pivo = v[r];

    int j = l;

    for(int k = l; k < r; k++){
        if(v[k] <= pivo)
            swap(&v[k], &v[j++]);
    }

    swap(&v[j], &v[r]);

    return j;
}

void quick_select(int *v, int l, int r, int target){
    if (r <= l) return;

    int p = separa(v, l, r);

    if(p > target) quick_select(v, l, p-1, target);
    if(p < target) quick_select(v, p+1, r, target);
}


// int main(){
//     int v[10] = {23, 21, 432, 53, 324, 26, 34, 12, 9, 10};

//     int k = 0;
    
//     quick_select(v, 0, 9, k);

//     printf("%d\n", v[k]);

//     return 0;
// }