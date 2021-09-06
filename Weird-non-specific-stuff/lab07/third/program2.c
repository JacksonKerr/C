#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_CHARS 80

void *emalloc(size_t s) {
    int *result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    return result;
}

void prSmol(char **a, int len, double ave) {
    if (len > 0) {
        if (strlen(a[0]) > ave) {
            fprintf(stdout, "%s\n", a[0]);
        }
        prSmol(&a[1], len-1, ave);
    }
}

int main() {
    char wrd[MAX_CHARS];
    char *wrds[MAX_WORDS];
    int len = 0;
    double avelen = 0;
    while (len < MAX_WORDS && scanf("%79s", wrd) == 1) {
        wrds[len] = emalloc(strlen(wrd)*sizeof wrds[0][0]);
        strcpy(wrds[len], wrd);
        len++;
        avelen += strlen(wrd);
    }
    avelen /= len;
    if (len > 0) {
        prSmol(wrds, len, avelen);
        fprintf(stderr, "%.2f\n", avelen);
    }
    return EXIT_SUCCESS;
}
