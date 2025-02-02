#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define ASCII_RANGE 256

typedef struct {
    char character;
    int frequency;
} CharFreq;

int compare(const void *a, const void *b) {
    CharFreq *x = (CharFreq *)a;
    CharFreq *y = (CharFreq *)b;

    if (x->frequency == y->frequency) {
        return x->character - y->character;
    }
    return x->frequency - y->frequency;
}

int main() {
    char line[MAX_LEN];
    int isFirst = 1;

    while (fgets(line, MAX_LEN, stdin)) {
        if (!isFirst) {
            printf("\n");
        }
        isFirst = 0;

        int freq[ASCII_RANGE] = {0};

        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            freq[(unsigned char)line[i]]++;
        }

        CharFreq charFreqs[MAX_LEN];
        int count = 0;
        for (int i = 0; i < ASCII_RANGE; i++) {
            if (freq[i] > 0) {
                charFreqs[count].character = i;
                charFreqs[count].frequency = freq[i];
                count++;
            }
        }

        qsort(charFreqs, count, sizeof(CharFreq), compare);

        for (int i = 0; i < count; i++) {
            printf("%d %d\n", charFreqs[i].character, charFreqs[i].frequency);
        }
    }

    printf("\n");
    return 0;
}
