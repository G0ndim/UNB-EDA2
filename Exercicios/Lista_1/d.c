#include <stdio.h>

int MenorElemento(int a, int b, int c) {
    if (b <= a && b <= c) {
        return b;
    }
    else if (c <= a && c <= b) {
        return c;
    }
    else{
        return a;
    }
}

int main(){
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    int crocante = a / 5;
    b -= 25 * crocante;
    c -= 20 * crocante;

    int misto = b / 25;
    c -= 25 * misto;

    int tradicional = c / 50;

    int sortida = 0, predileta = 0, especial = 0;

    if (tradicional >= 10 && misto >= 10 && crocante >= 10) {
        sortida = MenorElemento(tradicional / 10, misto / 10, crocante / 10);
        crocante -= sortida * 10;
        misto -= sortida * 10;
        tradicional -= sortida * 10;
    }

    if (misto >= 20 && crocante >= 10) {
        predileta = MenorElemento(misto / 20, crocante / 10, crocante / 10);
        crocante -= predileta * 10;
        misto -= predileta * 20;
    }

    if (crocante >= 30) {
        especial = crocante / 30;
    }

    printf("%d %d %d\n", especial, predileta, sortida);
    
    return 0;
}