#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 500
#define MAX_WORD_SIZE 25
#define SEARCH_WORD "Ethan"

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int contains(char **a, int len, char* word) {
    int cmp = strcmp(word, a[len / 2]);
    if (len == 0) {
        return 0;
    }
    if (cmp == 0) {
        return 1;
    }
    if (cmp < 0) {
        return contains(a, (len/2) - 1, word);
    }
    return contains(&a[len/2], len/2, word);
}

void printArr(char **a, int len) {
    if (len == 0) {
        return;
    }
    printf("%s\n", a[0]);
    printArr(++a, len-1);
}

int main() {
    int i;
    int aLen = 0;
    char *a[MAX_WORDS];
    char word[MAX_WORD_SIZE];
    while (aLen < MAX_WORDS && 1 == scanf("%24s", word)) {
        a[aLen] = emalloc((strlen(word)+1)*sizeof a[0][0]);
        strcpy(a[aLen], word);
        aLen++;
    }
    printArr(a, aLen);
    i = contains(a, aLen, SEARCH_WORD);
    if (i) {
        printf("Found\n %d", i);
    } else {
        printf("Not found %d\n", i);
    }
    
    return EXIT_SUCCESS;
}
