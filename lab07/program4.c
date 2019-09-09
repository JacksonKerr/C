#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_WORDS 100
#define MAX_LENGTH 80

void *emalloc(size_t s) {
    int *addy = malloc(s);
    if (addy == null) {
        fprintf(stderr, "Memory allocation faield");
        exit(EXIT_FAILURE);
    }
    return addy;
}

void printGreater(char **a, int len, double max) {
    if (len < 1) {
        return;
    }
    if (strlen(a[0]) > max) {
        fprintf(stdout, "%s\n", a[0]);
    }
    
}


int main() {
    char word[MAX_LENGTH];
    char *words[MAX_WORDS];
    int len = 0;
    int i = 0;
    double ave = 0;
    while (len < MAX_WORDS && 1 == scanf("%79s", word)) {
        words[len] = emalloc((strlen(word)+1)*sizeof words[0][0]);
        strcpy(words[len], word);
        len++;
        ave += strlen(word);
    }
    ave /= len;
    if (len > 0) {
        printGreater(words, len, ave);
        fprintf(stderr, "%.2f", ave);
    }
    for (i = 0; i < len; i++) {
        free(words[i]);
    }
    return EXIT_SUCCESS;
}
