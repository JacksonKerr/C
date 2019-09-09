#include <stdio.h>
#include <stdlib.h>
#include "ealloc.h"


void *emalloc(size_t s) {
    int *result = malloc(s);
    if (result != NULL) {
        return result;
    }
    fprintf(stderr, "Memory allocation failed");
    exit(EXIT_FAILURE);
}
void *erealloc(void *a, size_t s) {
    int *result = realloc(a, s);
    if (result != NULL) {
        return result;
    }
    fprintf(stderr, "Memory allocation failed");
    exit(EXIT_FAILURE);
}
