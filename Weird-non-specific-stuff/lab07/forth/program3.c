#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 80

void *emalloc(size_t s) {
    int *result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return result;
}

void printAve(char **a, int len, double ave) {
    if (len < 1) {
        return;
    }
    if (strlen(a[0]) > ave) {
        fprintf(stdout, "%s\n", a[0]);
    }
    printAve(&a[1], len-1, ave);
}

int main() {
    char word[MAX_LENGTH];
    char *words[MAX_WORDS];
    int len = 0;
    double avelen = 0;
    int i = 0;
    while (len < MAX_WORDS && 1 == scanf("%79s", word)) {
        words[len] = emalloc(strlen(word)*sizeof words[0][0]);
        avelen += strlen(word);
        strcpy(words[len], word);
        len++;
    }
    avelen /= len;
    if (len > 0) {
        printAve(words, len, avelen);
        
        for (i = 0; i < len; i++) {
            free(words[i]);
        }
        fprintf(stderr, "%.2f\n", avelen);
    }
    return EXIT_SUCCESS;
}
