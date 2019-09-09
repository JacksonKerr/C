#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory Allocatin Failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
void *erealloc(void* a, size_t s) {
    void *result = realloc(a, s);
    if (result == NULL) {
        fprintf(stderr, "Memory Allocatin Failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
struct flexarraydef {
    int len;
    int maxLen;
    int* array;
};

flexarray flex_new() {
    flexarray result = emalloc(sizeof *result);
    result->len = 0;
    result->maxLen = 2;
    result->array = emalloc(2*sizeof(result[0]));
}

void flex_free(flexarray f) {
    free(f->array);
}

void flex_print(flexarray f) {
    int i;
    for (i = 0; i < f->len; i++) {
        printf("%d ", f->array[i]);
    }
}

void flex_sort(flexarray f) {
    int move;
    int i;
    int temp;
    for (i = f->len-1; i > 0; i--) {
        move = i;
        while (f->array[move] < f->array[move-1]) {       
            temp = f->array[move+1];
            f->array[move+1] = f->array[move];
            f->array[move] = temp;
            move--;
        }
    }
}