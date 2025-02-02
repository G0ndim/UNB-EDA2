#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 216
#define MAX_WORD_LEN 16

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} WordCount;

WordCount wordList[MAX_WORDS];
int wordCount = 0;

int findWord(const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addVote(const char *word) {
    int index = findWord(word);
    if (index == -1) {
        if (wordCount < MAX_WORDS) {
            strcpy(wordList[wordCount].word, word);
            wordList[wordCount].count = 1;
            wordCount++;
        }
    } else {
        wordList[index].count++;
    }
}

void queryVotes(const char *word) {
    int index = findWord(word);
    if (index == -1) {
        printf("0\n");
    } else {
        printf("%d\n", wordList[index].count);
    }
}

void resetVotes(const char *word) {
    int index = findWord(word);
    if (index != -1) {
        wordList[index].count = 0;
    }
}

int main() {
    int cmd;
    char word[MAX_WORD_LEN + 1];

    while (scanf("%d %s", &cmd, word) != EOF) {
        if (cmd == 1) {
            addVote(word);
        } else if (cmd == 2) {
            queryVotes(word);
        } else if (cmd == 3) {
            resetVotes(word);
        }
    }

    return 0;
}
